(option
  (set_keyword) @keyword
  (skip_keyword) @type
  (on_keyword) @keyword
)

(option
  (set_keyword) @keyword
  [
    (reassemble_keyword)
    (optimization_keyword)
    (ruleset_optimization_keyword)
    (timeout_keyword)
    (limit_keyword)
    (loginterface_keyword)
    (hostid_keyword)
    (block_policy_keyword)
    (fail_policy_keyword)
    (require_order_keyword)
    (fingerprints_keyword)
    (state_policy_keyword)
    (state_defaults_keyword)
    (syncookies_keyword)
  ] @type
)

(comment) @comment
(number) @constant.builtin
(hex_number) @constant.builtin
(string) @string

"{" @punctuation.bracket
"}" @punctuation.bracket
"<" @punctuation.bracket
">" @punctuation.bracket

"," @punctuation.delimiter

(not_operator) @operator
"/" @operator
