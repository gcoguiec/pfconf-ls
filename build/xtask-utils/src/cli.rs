use core::fmt;
use std::{
    cell::OnceCell,
    io::{self, Error as IoError}
};

use miette::{Diagnostic, Result};
use nu_ansi_term::{AnsiGenericString, Color};
use thiserror::Error;

#[derive(Debug, Error, Diagnostic)]
pub enum AnswerError<'q> {
    #[error(
        "'{current_answer}' isn't a valid answer. Available answers: \
         {available_answers}."
    )]
    #[diagnostic(code(xtask::utils::cli::answer::invalid_error))]
    Invalid {
        current_answer: String,
        available_answers: &'q String
    }
}

#[derive(Debug, Clone)]
pub struct Answer {
    pub value: String
}

impl Answer {
    /// Checks if the answer is yes.
    pub fn is_yes(&self) -> bool {
        matches!(self.value.to_lowercase().as_str(), "y" | "yes")
    }
}

#[derive(Debug, Error, Diagnostic)]
pub enum QuestionError {
    #[error("Couldn't read the user input. {0}")]
    #[diagnostic(code(xtask::utils::cli::question::input_error))]
    Input(IoError)
}

#[derive(Debug)]
pub struct Question<'q> {
    pub target: AnsiGenericString<'q, str>,
    pub message: String,
    pub default_answer: Option<Answer>,
    pub locked_answers: Vec<Answer>,
    pub formatted_locked_answers: OnceCell<String>,
    pub last_answer: Option<Answer>
}

impl<'q> fmt::Display for Question<'q> {
    fn fmt(&self, formatter: &mut fmt::Formatter) -> fmt::Result {
        if self.locked_answers.is_empty() {
            return write!(formatter, "{}", self.message)
        }
        write!(
            formatter,
            "{} [{}]",
            &self.message,
            self.format_locked_answers()
        )
    }
}

impl<'q> Question<'q> {
    /// Creates a question with no locked answers per default.
    pub fn new(message: String) -> Self {
        Self {
            target: Color::DarkGray.paint("[xtask::question]"),
            message,
            default_answer: None,
            locked_answers: Vec::new(),
            formatted_locked_answers: OnceCell::new(),
            last_answer: None
        }
    }

    /// Formats the locked answers as a selection of choices.
    pub fn format_locked_answers(&self) -> &String {
        self.formatted_locked_answers.get_or_init(|| {
            self.locked_answers
                .iter()
                .map(|answer| answer.value.to_owned())
                .collect::<Vec<String>>()
                .join("|")
        })
    }

    /// Registers a locked answer for this question.
    pub fn register_answer(&mut self, value: &str) -> &mut Self {
        self.locked_answers.push(Answer {
            value: value.to_string()
        });
        self
    }

    /// Sets default answer if question is left unanswered.
    pub fn default_answer(&mut self, value: &str) -> &mut Self {
        self.default_answer = Some(Answer {
            value: value.to_string()
        });
        self
    }

    /// Asks the question and collects the user input.
    pub fn ask(&mut self) -> Result<&Answer, QuestionError> {
        loop {
            println!("{} {self}", self.target);
            let mut input = String::new();
            if let Err(err) = io::stdin().read_line(&mut input) {
                return Err(QuestionError::Input(err))
            }
            input = input.trim().to_string();
            if input.is_empty() && self.default_answer.is_some() {
                return Ok(self.default_answer.as_ref().unwrap());
            }
            self.last_answer = Some(Answer {
                value: input.to_owned()
            });
            if self.locked_answers.is_empty() {
                return Ok(self.last_answer.as_ref().unwrap())
            }
            for answer in &self.locked_answers {
                if answer.value.starts_with(&input) {
                    return Ok(answer)
                }
            }
            println!("{} {}", self.target, AnswerError::Invalid {
                current_answer: input,
                available_answers: &self
                    .format_locked_answers()
                    .replace('|', ",")
            });
        }
    }
}
