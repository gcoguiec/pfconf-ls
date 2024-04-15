#include "tree_sitter/parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#ifdef _MSC_VER
#pragma optimize("", off)
#elif defined(__clang__)
#pragma clang optimize off
#elif defined(__GNUC__)
#pragma GCC optimize ("O0")
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 113
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 236
#define ALIAS_COUNT 0
#define TOKEN_COUNT 193
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 6
#define MAX_ALIAS_SEQUENCE_LENGTH 5
#define PRODUCTION_ID_COUNT 14

enum ts_symbol_identifiers {
  sym_identifier = 1,
  anon_sym_POUND = 2,
  aux_sym_comment_token1 = 3,
  anon_sym_LBRACE = 4,
  anon_sym_RBRACE = 5,
  anon_sym_none = 6,
  anon_sym_yes = 7,
  anon_sym_no = 8,
  anon_sym_if_DASHbound = 9,
  anon_sym_floating = 10,
  anon_sym_urgent = 11,
  anon_sym_misc = 12,
  anon_sym_loud = 13,
  anon_sym_never = 14,
  anon_sym_adaptative = 15,
  anon_sym_always = 16,
  anon_sym_normal = 17,
  anon_sym_satellite = 18,
  anon_sym_high_DASHlatency = 19,
  anon_sym_conservative = 20,
  anon_sym_aggressive = 21,
  anon_sym_basic = 22,
  anon_sym_profile = 23,
  anon_sym_COMMA = 24,
  anon_sym_tcp_DOTfirst = 25,
  anon_sym_tcp_DOTopening = 26,
  anon_sym_tcp_DOTestablished = 27,
  anon_sym_tcp_DOTclosing = 28,
  anon_sym_tcp_DOTfinwait = 29,
  anon_sym_tcp_DOTclosed = 30,
  anon_sym_tcp_DOTtsdiff = 31,
  anon_sym_sctp_DOTopening = 32,
  anon_sym_sctp_DOTestablished = 33,
  anon_sym_sctp_DOTclosing = 34,
  anon_sym_sctp_DOTclosed = 35,
  anon_sym_udp_DOTfirst = 36,
  anon_sym_udp_DOTsingle = 37,
  anon_sym_udp_DOTmultiple = 38,
  anon_sym_icmp_DOTfirst = 39,
  anon_sym_icmp_DOTerror = 40,
  anon_sym_other_DOTfirst = 41,
  anon_sym_other_DOTsingle = 42,
  anon_sym_other_DOTmultiple = 43,
  anon_sym_frag = 44,
  anon_sym_interval = 45,
  anon_sym_adaptive_DOTstart = 46,
  anon_sym_adaptive_DOTend = 47,
  anon_sym_src_DOTtrack = 48,
  anon_sym_states = 49,
  anon_sym_src_DASHnodes = 50,
  anon_sym_frags = 51,
  anon_sym_table_DASHentries = 52,
  anon_sym_SLASH = 53,
  anon_sym_LT = 54,
  anon_sym_GT = 55,
  anon_sym_DQUOTE = 56,
  aux_sym_string_token1 = 57,
  sym_number = 58,
  sym_hex_number = 59,
  sym_not_operator = 60,
  sym_all_keyword = 61,
  sym_allow_opts_keyword = 62,
  sym_altq_keyword = 63,
  sym_anchor_keyword = 64,
  sym_antispoof_keyword = 65,
  sym_any_keyword = 66,
  sym_bandwidth_keyword = 67,
  sym_binat_keyword = 68,
  sym_binat_anchor_keyword = 69,
  sym_bitmask_keyword = 70,
  sym_block_keyword = 71,
  sym_block_policy_keyword = 72,
  sym_bridge_to_keyword = 73,
  sym_buckets_keyword = 74,
  sym_cbq_keyword = 75,
  sym_code_keyword = 76,
  sym_codelq_keyword = 77,
  sym_debug_keyword = 78,
  sym_divert_reply_keyword = 79,
  sym_divert_to_keyword = 80,
  sym_dnpipe_keyword = 81,
  sym_dnqueue_keyword = 82,
  sym_drop_keyword = 83,
  sym_dup_to_keyword = 84,
  sym_ether_keyword = 85,
  sym_fail_policy_keyword = 86,
  sym_fairq_keyword = 87,
  sym_fastroute_keyword = 88,
  sym_file_keyword = 89,
  sym_fingerprints_keyword = 90,
  sym_flags_keyword = 91,
  sym_flush_keyword = 92,
  sym_for_keyword = 93,
  sym_fragment_keyword = 94,
  sym_from_keyword = 95,
  sym_global_keyword = 96,
  sym_group_keyword = 97,
  sym_hfsc_keyword = 98,
  sym_hogs_keyword = 99,
  sym_hostid_keyword = 100,
  sym_icmp_type_keyword = 101,
  sym_icmp6_type_keyword = 102,
  sym_in_keyword = 103,
  sym_include_keyword = 104,
  sym_inet_keyword = 105,
  sym_inet6_keyword = 106,
  sym_keep_keyword = 107,
  sym_keepcounters_keyword = 108,
  sym_l3_keyword = 109,
  sym_label_keyword = 110,
  sym_limit_keyword = 111,
  sym_linkshare_keyword = 112,
  sym_load_keyword = 113,
  sym_log_keyword = 114,
  sym_loginterface_keyword = 115,
  sym_map_e_portset_keyword = 116,
  sym_match_keyword = 117,
  sym_max_keyword = 118,
  sym_max_mss_keyword = 119,
  sym_max_src_conn_keyword = 120,
  sym_max_src_conn_rate_keyword = 121,
  sym_max_src_nodes_keyword = 122,
  sym_max_src_states_keyword = 123,
  sym_min_ttl_keyword = 124,
  sym_modulate_keyword = 125,
  sym_nat_keyword = 126,
  sym_nat_anchor_keyword = 127,
  sym_no_df_keyword = 128,
  sym_no_route_keyword = 129,
  sym_no_sync_keyword = 130,
  sym_on_keyword = 131,
  sym_optimization_keyword = 132,
  sym_os_keyword = 133,
  sym_out_keyword = 134,
  sym_overload_keyword = 135,
  sym_pass_keyword = 136,
  sym_pflow_keyword = 137,
  sym_port_keyword = 138,
  sym_prio_keyword = 139,
  sym_priority_keyword = 140,
  sym_priq_keyword = 141,
  sym_probability_keyword = 142,
  sym_proto_keyword = 143,
  sym_qlimit_keyword = 144,
  sym_queue_keyword = 145,
  sym_quick_keyword = 146,
  sym_random_keyword = 147,
  sym_random_id_keyword = 148,
  sym_rdr_keyword = 149,
  sym_rdr_anchor_keyword = 150,
  sym_realtime_keyword = 151,
  sym_reassemble_keyword = 152,
  sym_reply_to_keyword = 153,
  sym_require_order_keyword = 154,
  sym_return_keyword = 155,
  sym_return_icmp_keyword = 156,
  sym_return_icmp6_keyword = 157,
  sym_return_rst_keyword = 158,
  sym_ridentifier_keyword = 159,
  sym_round_robin_keyword = 160,
  sym_route_keyword = 161,
  sym_route_to_keyword = 162,
  sym_rtable_keyword = 163,
  sym_rule_keyword = 164,
  sym_ruleset_optimization_keyword = 165,
  sym_scrub_keyword = 166,
  sym_self_keyword = 167,
  sym_set_keyword = 168,
  sym_set_tos_keyword = 169,
  sym_skip_keyword = 170,
  sym_sloppy_keyword = 171,
  sym_source_hash_keyword = 172,
  sym_source_track_keyword = 173,
  sym_state_keyword = 174,
  sym_state_defaults_keyword = 175,
  sym_state_policy_keyword = 176,
  sym_static_port_keyword = 177,
  sym_sticky_address_keyword = 178,
  sym_syncookies_keyword = 179,
  sym_synproxy_keyword = 180,
  sym_table_keyword = 181,
  sym_tag_keyword = 182,
  sym_tagged_keyword = 183,
  sym_target_keyword = 184,
  sym_tbrsize_keyword = 185,
  sym_timeout_keyword = 186,
  sym_to_keyword = 187,
  sym_tos_keyword = 188,
  sym_ttl_keyword = 189,
  sym_upperlimit_keyword = 190,
  sym_urpf_failed_keyword = 191,
  sym_user_keyword = 192,
  sym_lines = 193,
  sym_line = 194,
  sym_comment = 195,
  sym_option = 196,
  sym__reassemble_option = 197,
  sym__optimization_option = 198,
  sym__ruleset_optimization_option = 199,
  sym__timeout_option = 200,
  sym__limit_option = 201,
  sym__loginterface_option = 202,
  sym__hostid_option = 203,
  sym__block_policy_option = 204,
  sym__fail_policy_option = 205,
  sym__require_order_option = 206,
  sym__fingerprints_option = 207,
  sym__state_policy_option = 208,
  sym__debug_option = 209,
  sym__skip_option = 210,
  sym__state_defaults_option = 211,
  sym__keep_counters_option = 212,
  sym__syncookies_option = 213,
  sym_optimization_hint = 214,
  sym_ruleset_optimizer = 215,
  sym_timeout_list = 216,
  sym_timeout_spec = 217,
  sym_timeout_type = 218,
  sym_limit_list = 219,
  sym_limit_spec = 220,
  sym_ifspec = 221,
  sym_interface_list = 222,
  sym_interface = 223,
  sym_state_opt_list = 224,
  sym_state_opt = 225,
  sym_string = 226,
  sym_floating_keyword = 227,
  sym_if_bound_keyword = 228,
  sym_no_keyword = 229,
  sym_yes_keyword = 230,
  aux_sym_lines_repeat1 = 231,
  aux_sym_timeout_list_repeat1 = 232,
  aux_sym_limit_list_repeat1 = 233,
  aux_sym_interface_list_repeat1 = 234,
  aux_sym_state_opt_list_repeat1 = 235,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [sym_identifier] = "identifier",
  [anon_sym_POUND] = "#",
  [aux_sym_comment_token1] = "comment_token1",
  [anon_sym_LBRACE] = "{",
  [anon_sym_RBRACE] = "}",
  [anon_sym_none] = "none",
  [anon_sym_yes] = "yes",
  [anon_sym_no] = "no",
  [anon_sym_if_DASHbound] = "if-bound",
  [anon_sym_floating] = "floating",
  [anon_sym_urgent] = "urgent",
  [anon_sym_misc] = "misc",
  [anon_sym_loud] = "loud",
  [anon_sym_never] = "never",
  [anon_sym_adaptative] = "adaptative",
  [anon_sym_always] = "always",
  [anon_sym_normal] = "normal",
  [anon_sym_satellite] = "satellite",
  [anon_sym_high_DASHlatency] = "high-latency",
  [anon_sym_conservative] = "conservative",
  [anon_sym_aggressive] = "aggressive",
  [anon_sym_basic] = "basic",
  [anon_sym_profile] = "profile",
  [anon_sym_COMMA] = ",",
  [anon_sym_tcp_DOTfirst] = "tcp.first",
  [anon_sym_tcp_DOTopening] = "tcp.opening",
  [anon_sym_tcp_DOTestablished] = "tcp.established",
  [anon_sym_tcp_DOTclosing] = "tcp.closing",
  [anon_sym_tcp_DOTfinwait] = "tcp.finwait",
  [anon_sym_tcp_DOTclosed] = "tcp.closed",
  [anon_sym_tcp_DOTtsdiff] = "tcp.tsdiff",
  [anon_sym_sctp_DOTopening] = "sctp.opening",
  [anon_sym_sctp_DOTestablished] = "sctp.established",
  [anon_sym_sctp_DOTclosing] = "sctp.closing",
  [anon_sym_sctp_DOTclosed] = "sctp.closed",
  [anon_sym_udp_DOTfirst] = "udp.first",
  [anon_sym_udp_DOTsingle] = "udp.single",
  [anon_sym_udp_DOTmultiple] = "udp.multiple",
  [anon_sym_icmp_DOTfirst] = "icmp.first",
  [anon_sym_icmp_DOTerror] = "icmp.error",
  [anon_sym_other_DOTfirst] = "other.first",
  [anon_sym_other_DOTsingle] = "other.single",
  [anon_sym_other_DOTmultiple] = "other.multiple",
  [anon_sym_frag] = "frag",
  [anon_sym_interval] = "interval",
  [anon_sym_adaptive_DOTstart] = "adaptive.start",
  [anon_sym_adaptive_DOTend] = "adaptive.end",
  [anon_sym_src_DOTtrack] = "src.track",
  [anon_sym_states] = "states",
  [anon_sym_src_DASHnodes] = "src-nodes",
  [anon_sym_frags] = "frags",
  [anon_sym_table_DASHentries] = "table-entries",
  [anon_sym_SLASH] = "/",
  [anon_sym_LT] = "<",
  [anon_sym_GT] = ">",
  [anon_sym_DQUOTE] = "\"",
  [aux_sym_string_token1] = "string_token1",
  [sym_number] = "number",
  [sym_hex_number] = "hex_number",
  [sym_not_operator] = "not_operator",
  [sym_all_keyword] = "all_keyword",
  [sym_allow_opts_keyword] = "allow_opts_keyword",
  [sym_altq_keyword] = "altq_keyword",
  [sym_anchor_keyword] = "anchor_keyword",
  [sym_antispoof_keyword] = "antispoof_keyword",
  [sym_any_keyword] = "any_keyword",
  [sym_bandwidth_keyword] = "bandwidth_keyword",
  [sym_binat_keyword] = "binat_keyword",
  [sym_binat_anchor_keyword] = "binat_anchor_keyword",
  [sym_bitmask_keyword] = "bitmask_keyword",
  [sym_block_keyword] = "block_keyword",
  [sym_block_policy_keyword] = "block_policy_keyword",
  [sym_bridge_to_keyword] = "bridge_to_keyword",
  [sym_buckets_keyword] = "buckets_keyword",
  [sym_cbq_keyword] = "cbq_keyword",
  [sym_code_keyword] = "code_keyword",
  [sym_codelq_keyword] = "codelq_keyword",
  [sym_debug_keyword] = "debug_keyword",
  [sym_divert_reply_keyword] = "divert_reply_keyword",
  [sym_divert_to_keyword] = "divert_to_keyword",
  [sym_dnpipe_keyword] = "dnpipe_keyword",
  [sym_dnqueue_keyword] = "dnqueue_keyword",
  [sym_drop_keyword] = "drop_keyword",
  [sym_dup_to_keyword] = "dup_to_keyword",
  [sym_ether_keyword] = "ether_keyword",
  [sym_fail_policy_keyword] = "fail_policy_keyword",
  [sym_fairq_keyword] = "fairq_keyword",
  [sym_fastroute_keyword] = "fastroute_keyword",
  [sym_file_keyword] = "file_keyword",
  [sym_fingerprints_keyword] = "fingerprints_keyword",
  [sym_flags_keyword] = "flags_keyword",
  [sym_flush_keyword] = "flush_keyword",
  [sym_for_keyword] = "for_keyword",
  [sym_fragment_keyword] = "fragment_keyword",
  [sym_from_keyword] = "from_keyword",
  [sym_global_keyword] = "global_keyword",
  [sym_group_keyword] = "group_keyword",
  [sym_hfsc_keyword] = "hfsc_keyword",
  [sym_hogs_keyword] = "hogs_keyword",
  [sym_hostid_keyword] = "hostid_keyword",
  [sym_icmp_type_keyword] = "icmp_type_keyword",
  [sym_icmp6_type_keyword] = "icmp6_type_keyword",
  [sym_in_keyword] = "in_keyword",
  [sym_include_keyword] = "include_keyword",
  [sym_inet_keyword] = "inet_keyword",
  [sym_inet6_keyword] = "inet6_keyword",
  [sym_keep_keyword] = "keep_keyword",
  [sym_keepcounters_keyword] = "keepcounters_keyword",
  [sym_l3_keyword] = "l3_keyword",
  [sym_label_keyword] = "label_keyword",
  [sym_limit_keyword] = "limit_keyword",
  [sym_linkshare_keyword] = "linkshare_keyword",
  [sym_load_keyword] = "load_keyword",
  [sym_log_keyword] = "log_keyword",
  [sym_loginterface_keyword] = "loginterface_keyword",
  [sym_map_e_portset_keyword] = "map_e_portset_keyword",
  [sym_match_keyword] = "match_keyword",
  [sym_max_keyword] = "max_keyword",
  [sym_max_mss_keyword] = "max_mss_keyword",
  [sym_max_src_conn_keyword] = "max_src_conn_keyword",
  [sym_max_src_conn_rate_keyword] = "max_src_conn_rate_keyword",
  [sym_max_src_nodes_keyword] = "max_src_nodes_keyword",
  [sym_max_src_states_keyword] = "max_src_states_keyword",
  [sym_min_ttl_keyword] = "min_ttl_keyword",
  [sym_modulate_keyword] = "modulate_keyword",
  [sym_nat_keyword] = "nat_keyword",
  [sym_nat_anchor_keyword] = "nat_anchor_keyword",
  [sym_no_df_keyword] = "no_df_keyword",
  [sym_no_route_keyword] = "no_route_keyword",
  [sym_no_sync_keyword] = "no_sync_keyword",
  [sym_on_keyword] = "on_keyword",
  [sym_optimization_keyword] = "optimization_keyword",
  [sym_os_keyword] = "os_keyword",
  [sym_out_keyword] = "out_keyword",
  [sym_overload_keyword] = "overload_keyword",
  [sym_pass_keyword] = "pass_keyword",
  [sym_pflow_keyword] = "pflow_keyword",
  [sym_port_keyword] = "port_keyword",
  [sym_prio_keyword] = "prio_keyword",
  [sym_priority_keyword] = "priority_keyword",
  [sym_priq_keyword] = "priq_keyword",
  [sym_probability_keyword] = "probability_keyword",
  [sym_proto_keyword] = "proto_keyword",
  [sym_qlimit_keyword] = "qlimit_keyword",
  [sym_queue_keyword] = "queue_keyword",
  [sym_quick_keyword] = "quick_keyword",
  [sym_random_keyword] = "random_keyword",
  [sym_random_id_keyword] = "random_id_keyword",
  [sym_rdr_keyword] = "rdr_keyword",
  [sym_rdr_anchor_keyword] = "rdr_anchor_keyword",
  [sym_realtime_keyword] = "realtime_keyword",
  [sym_reassemble_keyword] = "reassemble_keyword",
  [sym_reply_to_keyword] = "reply_to_keyword",
  [sym_require_order_keyword] = "require_order_keyword",
  [sym_return_keyword] = "return_keyword",
  [sym_return_icmp_keyword] = "return_icmp_keyword",
  [sym_return_icmp6_keyword] = "return_icmp6_keyword",
  [sym_return_rst_keyword] = "return_rst_keyword",
  [sym_ridentifier_keyword] = "ridentifier_keyword",
  [sym_round_robin_keyword] = "round_robin_keyword",
  [sym_route_keyword] = "route_keyword",
  [sym_route_to_keyword] = "route_to_keyword",
  [sym_rtable_keyword] = "rtable_keyword",
  [sym_rule_keyword] = "rule_keyword",
  [sym_ruleset_optimization_keyword] = "ruleset_optimization_keyword",
  [sym_scrub_keyword] = "scrub_keyword",
  [sym_self_keyword] = "self_keyword",
  [sym_set_keyword] = "set_keyword",
  [sym_set_tos_keyword] = "set_tos_keyword",
  [sym_skip_keyword] = "skip_keyword",
  [sym_sloppy_keyword] = "sloppy_keyword",
  [sym_source_hash_keyword] = "source_hash_keyword",
  [sym_source_track_keyword] = "source_track_keyword",
  [sym_state_keyword] = "state_keyword",
  [sym_state_defaults_keyword] = "state_defaults_keyword",
  [sym_state_policy_keyword] = "state_policy_keyword",
  [sym_static_port_keyword] = "static_port_keyword",
  [sym_sticky_address_keyword] = "sticky_address_keyword",
  [sym_syncookies_keyword] = "syncookies_keyword",
  [sym_synproxy_keyword] = "synproxy_keyword",
  [sym_table_keyword] = "table_keyword",
  [sym_tag_keyword] = "tag_keyword",
  [sym_tagged_keyword] = "tagged_keyword",
  [sym_target_keyword] = "target_keyword",
  [sym_tbrsize_keyword] = "tbrsize_keyword",
  [sym_timeout_keyword] = "timeout_keyword",
  [sym_to_keyword] = "to_keyword",
  [sym_tos_keyword] = "tos_keyword",
  [sym_ttl_keyword] = "ttl_keyword",
  [sym_upperlimit_keyword] = "upperlimit_keyword",
  [sym_urpf_failed_keyword] = "urpf_failed_keyword",
  [sym_user_keyword] = "user_keyword",
  [sym_lines] = "lines",
  [sym_line] = "line",
  [sym_comment] = "comment",
  [sym_option] = "option",
  [sym__reassemble_option] = "_reassemble_option",
  [sym__optimization_option] = "_optimization_option",
  [sym__ruleset_optimization_option] = "_ruleset_optimization_option",
  [sym__timeout_option] = "_timeout_option",
  [sym__limit_option] = "_limit_option",
  [sym__loginterface_option] = "_loginterface_option",
  [sym__hostid_option] = "_hostid_option",
  [sym__block_policy_option] = "_block_policy_option",
  [sym__fail_policy_option] = "_fail_policy_option",
  [sym__require_order_option] = "_require_order_option",
  [sym__fingerprints_option] = "_fingerprints_option",
  [sym__state_policy_option] = "_state_policy_option",
  [sym__debug_option] = "_debug_option",
  [sym__skip_option] = "_skip_option",
  [sym__state_defaults_option] = "_state_defaults_option",
  [sym__keep_counters_option] = "_keep_counters_option",
  [sym__syncookies_option] = "_syncookies_option",
  [sym_optimization_hint] = "optimization_hint",
  [sym_ruleset_optimizer] = "ruleset_optimizer",
  [sym_timeout_list] = "timeout_list",
  [sym_timeout_spec] = "timeout_spec",
  [sym_timeout_type] = "timeout_type",
  [sym_limit_list] = "limit_list",
  [sym_limit_spec] = "limit_spec",
  [sym_ifspec] = "ifspec",
  [sym_interface_list] = "interface_list",
  [sym_interface] = "interface",
  [sym_state_opt_list] = "state_opt_list",
  [sym_state_opt] = "state_opt",
  [sym_string] = "string",
  [sym_floating_keyword] = "floating_keyword",
  [sym_if_bound_keyword] = "if_bound_keyword",
  [sym_no_keyword] = "no_keyword",
  [sym_yes_keyword] = "yes_keyword",
  [aux_sym_lines_repeat1] = "lines_repeat1",
  [aux_sym_timeout_list_repeat1] = "timeout_list_repeat1",
  [aux_sym_limit_list_repeat1] = "limit_list_repeat1",
  [aux_sym_interface_list_repeat1] = "interface_list_repeat1",
  [aux_sym_state_opt_list_repeat1] = "state_opt_list_repeat1",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [sym_identifier] = sym_identifier,
  [anon_sym_POUND] = anon_sym_POUND,
  [aux_sym_comment_token1] = aux_sym_comment_token1,
  [anon_sym_LBRACE] = anon_sym_LBRACE,
  [anon_sym_RBRACE] = anon_sym_RBRACE,
  [anon_sym_none] = anon_sym_none,
  [anon_sym_yes] = anon_sym_yes,
  [anon_sym_no] = anon_sym_no,
  [anon_sym_if_DASHbound] = anon_sym_if_DASHbound,
  [anon_sym_floating] = anon_sym_floating,
  [anon_sym_urgent] = anon_sym_urgent,
  [anon_sym_misc] = anon_sym_misc,
  [anon_sym_loud] = anon_sym_loud,
  [anon_sym_never] = anon_sym_never,
  [anon_sym_adaptative] = anon_sym_adaptative,
  [anon_sym_always] = anon_sym_always,
  [anon_sym_normal] = anon_sym_normal,
  [anon_sym_satellite] = anon_sym_satellite,
  [anon_sym_high_DASHlatency] = anon_sym_high_DASHlatency,
  [anon_sym_conservative] = anon_sym_conservative,
  [anon_sym_aggressive] = anon_sym_aggressive,
  [anon_sym_basic] = anon_sym_basic,
  [anon_sym_profile] = anon_sym_profile,
  [anon_sym_COMMA] = anon_sym_COMMA,
  [anon_sym_tcp_DOTfirst] = anon_sym_tcp_DOTfirst,
  [anon_sym_tcp_DOTopening] = anon_sym_tcp_DOTopening,
  [anon_sym_tcp_DOTestablished] = anon_sym_tcp_DOTestablished,
  [anon_sym_tcp_DOTclosing] = anon_sym_tcp_DOTclosing,
  [anon_sym_tcp_DOTfinwait] = anon_sym_tcp_DOTfinwait,
  [anon_sym_tcp_DOTclosed] = anon_sym_tcp_DOTclosed,
  [anon_sym_tcp_DOTtsdiff] = anon_sym_tcp_DOTtsdiff,
  [anon_sym_sctp_DOTopening] = anon_sym_sctp_DOTopening,
  [anon_sym_sctp_DOTestablished] = anon_sym_sctp_DOTestablished,
  [anon_sym_sctp_DOTclosing] = anon_sym_sctp_DOTclosing,
  [anon_sym_sctp_DOTclosed] = anon_sym_sctp_DOTclosed,
  [anon_sym_udp_DOTfirst] = anon_sym_udp_DOTfirst,
  [anon_sym_udp_DOTsingle] = anon_sym_udp_DOTsingle,
  [anon_sym_udp_DOTmultiple] = anon_sym_udp_DOTmultiple,
  [anon_sym_icmp_DOTfirst] = anon_sym_icmp_DOTfirst,
  [anon_sym_icmp_DOTerror] = anon_sym_icmp_DOTerror,
  [anon_sym_other_DOTfirst] = anon_sym_other_DOTfirst,
  [anon_sym_other_DOTsingle] = anon_sym_other_DOTsingle,
  [anon_sym_other_DOTmultiple] = anon_sym_other_DOTmultiple,
  [anon_sym_frag] = anon_sym_frag,
  [anon_sym_interval] = anon_sym_interval,
  [anon_sym_adaptive_DOTstart] = anon_sym_adaptive_DOTstart,
  [anon_sym_adaptive_DOTend] = anon_sym_adaptive_DOTend,
  [anon_sym_src_DOTtrack] = anon_sym_src_DOTtrack,
  [anon_sym_states] = anon_sym_states,
  [anon_sym_src_DASHnodes] = anon_sym_src_DASHnodes,
  [anon_sym_frags] = anon_sym_frags,
  [anon_sym_table_DASHentries] = anon_sym_table_DASHentries,
  [anon_sym_SLASH] = anon_sym_SLASH,
  [anon_sym_LT] = anon_sym_LT,
  [anon_sym_GT] = anon_sym_GT,
  [anon_sym_DQUOTE] = anon_sym_DQUOTE,
  [aux_sym_string_token1] = aux_sym_string_token1,
  [sym_number] = sym_number,
  [sym_hex_number] = sym_hex_number,
  [sym_not_operator] = sym_not_operator,
  [sym_all_keyword] = sym_all_keyword,
  [sym_allow_opts_keyword] = sym_allow_opts_keyword,
  [sym_altq_keyword] = sym_altq_keyword,
  [sym_anchor_keyword] = sym_anchor_keyword,
  [sym_antispoof_keyword] = sym_antispoof_keyword,
  [sym_any_keyword] = sym_any_keyword,
  [sym_bandwidth_keyword] = sym_bandwidth_keyword,
  [sym_binat_keyword] = sym_binat_keyword,
  [sym_binat_anchor_keyword] = sym_binat_anchor_keyword,
  [sym_bitmask_keyword] = sym_bitmask_keyword,
  [sym_block_keyword] = sym_block_keyword,
  [sym_block_policy_keyword] = sym_block_policy_keyword,
  [sym_bridge_to_keyword] = sym_bridge_to_keyword,
  [sym_buckets_keyword] = sym_buckets_keyword,
  [sym_cbq_keyword] = sym_cbq_keyword,
  [sym_code_keyword] = sym_code_keyword,
  [sym_codelq_keyword] = sym_codelq_keyword,
  [sym_debug_keyword] = sym_debug_keyword,
  [sym_divert_reply_keyword] = sym_divert_reply_keyword,
  [sym_divert_to_keyword] = sym_divert_to_keyword,
  [sym_dnpipe_keyword] = sym_dnpipe_keyword,
  [sym_dnqueue_keyword] = sym_dnqueue_keyword,
  [sym_drop_keyword] = sym_drop_keyword,
  [sym_dup_to_keyword] = sym_dup_to_keyword,
  [sym_ether_keyword] = sym_ether_keyword,
  [sym_fail_policy_keyword] = sym_fail_policy_keyword,
  [sym_fairq_keyword] = sym_fairq_keyword,
  [sym_fastroute_keyword] = sym_fastroute_keyword,
  [sym_file_keyword] = sym_file_keyword,
  [sym_fingerprints_keyword] = sym_fingerprints_keyword,
  [sym_flags_keyword] = sym_flags_keyword,
  [sym_flush_keyword] = sym_flush_keyword,
  [sym_for_keyword] = sym_for_keyword,
  [sym_fragment_keyword] = sym_fragment_keyword,
  [sym_from_keyword] = sym_from_keyword,
  [sym_global_keyword] = sym_global_keyword,
  [sym_group_keyword] = sym_group_keyword,
  [sym_hfsc_keyword] = sym_hfsc_keyword,
  [sym_hogs_keyword] = sym_hogs_keyword,
  [sym_hostid_keyword] = sym_hostid_keyword,
  [sym_icmp_type_keyword] = sym_icmp_type_keyword,
  [sym_icmp6_type_keyword] = sym_icmp6_type_keyword,
  [sym_in_keyword] = sym_in_keyword,
  [sym_include_keyword] = sym_include_keyword,
  [sym_inet_keyword] = sym_inet_keyword,
  [sym_inet6_keyword] = sym_inet6_keyword,
  [sym_keep_keyword] = sym_keep_keyword,
  [sym_keepcounters_keyword] = sym_keepcounters_keyword,
  [sym_l3_keyword] = sym_l3_keyword,
  [sym_label_keyword] = sym_label_keyword,
  [sym_limit_keyword] = sym_limit_keyword,
  [sym_linkshare_keyword] = sym_linkshare_keyword,
  [sym_load_keyword] = sym_load_keyword,
  [sym_log_keyword] = sym_log_keyword,
  [sym_loginterface_keyword] = sym_loginterface_keyword,
  [sym_map_e_portset_keyword] = sym_map_e_portset_keyword,
  [sym_match_keyword] = sym_match_keyword,
  [sym_max_keyword] = sym_max_keyword,
  [sym_max_mss_keyword] = sym_max_mss_keyword,
  [sym_max_src_conn_keyword] = sym_max_src_conn_keyword,
  [sym_max_src_conn_rate_keyword] = sym_max_src_conn_rate_keyword,
  [sym_max_src_nodes_keyword] = sym_max_src_nodes_keyword,
  [sym_max_src_states_keyword] = sym_max_src_states_keyword,
  [sym_min_ttl_keyword] = sym_min_ttl_keyword,
  [sym_modulate_keyword] = sym_modulate_keyword,
  [sym_nat_keyword] = sym_nat_keyword,
  [sym_nat_anchor_keyword] = sym_nat_anchor_keyword,
  [sym_no_df_keyword] = sym_no_df_keyword,
  [sym_no_route_keyword] = sym_no_route_keyword,
  [sym_no_sync_keyword] = sym_no_sync_keyword,
  [sym_on_keyword] = sym_on_keyword,
  [sym_optimization_keyword] = sym_optimization_keyword,
  [sym_os_keyword] = sym_os_keyword,
  [sym_out_keyword] = sym_out_keyword,
  [sym_overload_keyword] = sym_overload_keyword,
  [sym_pass_keyword] = sym_pass_keyword,
  [sym_pflow_keyword] = sym_pflow_keyword,
  [sym_port_keyword] = sym_port_keyword,
  [sym_prio_keyword] = sym_prio_keyword,
  [sym_priority_keyword] = sym_priority_keyword,
  [sym_priq_keyword] = sym_priq_keyword,
  [sym_probability_keyword] = sym_probability_keyword,
  [sym_proto_keyword] = sym_proto_keyword,
  [sym_qlimit_keyword] = sym_qlimit_keyword,
  [sym_queue_keyword] = sym_queue_keyword,
  [sym_quick_keyword] = sym_quick_keyword,
  [sym_random_keyword] = sym_random_keyword,
  [sym_random_id_keyword] = sym_random_id_keyword,
  [sym_rdr_keyword] = sym_rdr_keyword,
  [sym_rdr_anchor_keyword] = sym_rdr_anchor_keyword,
  [sym_realtime_keyword] = sym_realtime_keyword,
  [sym_reassemble_keyword] = sym_reassemble_keyword,
  [sym_reply_to_keyword] = sym_reply_to_keyword,
  [sym_require_order_keyword] = sym_require_order_keyword,
  [sym_return_keyword] = sym_return_keyword,
  [sym_return_icmp_keyword] = sym_return_icmp_keyword,
  [sym_return_icmp6_keyword] = sym_return_icmp6_keyword,
  [sym_return_rst_keyword] = sym_return_rst_keyword,
  [sym_ridentifier_keyword] = sym_ridentifier_keyword,
  [sym_round_robin_keyword] = sym_round_robin_keyword,
  [sym_route_keyword] = sym_route_keyword,
  [sym_route_to_keyword] = sym_route_to_keyword,
  [sym_rtable_keyword] = sym_rtable_keyword,
  [sym_rule_keyword] = sym_rule_keyword,
  [sym_ruleset_optimization_keyword] = sym_ruleset_optimization_keyword,
  [sym_scrub_keyword] = sym_scrub_keyword,
  [sym_self_keyword] = sym_self_keyword,
  [sym_set_keyword] = sym_set_keyword,
  [sym_set_tos_keyword] = sym_set_tos_keyword,
  [sym_skip_keyword] = sym_skip_keyword,
  [sym_sloppy_keyword] = sym_sloppy_keyword,
  [sym_source_hash_keyword] = sym_source_hash_keyword,
  [sym_source_track_keyword] = sym_source_track_keyword,
  [sym_state_keyword] = sym_state_keyword,
  [sym_state_defaults_keyword] = sym_state_defaults_keyword,
  [sym_state_policy_keyword] = sym_state_policy_keyword,
  [sym_static_port_keyword] = sym_static_port_keyword,
  [sym_sticky_address_keyword] = sym_sticky_address_keyword,
  [sym_syncookies_keyword] = sym_syncookies_keyword,
  [sym_synproxy_keyword] = sym_synproxy_keyword,
  [sym_table_keyword] = sym_table_keyword,
  [sym_tag_keyword] = sym_tag_keyword,
  [sym_tagged_keyword] = sym_tagged_keyword,
  [sym_target_keyword] = sym_target_keyword,
  [sym_tbrsize_keyword] = sym_tbrsize_keyword,
  [sym_timeout_keyword] = sym_timeout_keyword,
  [sym_to_keyword] = sym_to_keyword,
  [sym_tos_keyword] = sym_tos_keyword,
  [sym_ttl_keyword] = sym_ttl_keyword,
  [sym_upperlimit_keyword] = sym_upperlimit_keyword,
  [sym_urpf_failed_keyword] = sym_urpf_failed_keyword,
  [sym_user_keyword] = sym_user_keyword,
  [sym_lines] = sym_lines,
  [sym_line] = sym_line,
  [sym_comment] = sym_comment,
  [sym_option] = sym_option,
  [sym__reassemble_option] = sym__reassemble_option,
  [sym__optimization_option] = sym__optimization_option,
  [sym__ruleset_optimization_option] = sym__ruleset_optimization_option,
  [sym__timeout_option] = sym__timeout_option,
  [sym__limit_option] = sym__limit_option,
  [sym__loginterface_option] = sym__loginterface_option,
  [sym__hostid_option] = sym__hostid_option,
  [sym__block_policy_option] = sym__block_policy_option,
  [sym__fail_policy_option] = sym__fail_policy_option,
  [sym__require_order_option] = sym__require_order_option,
  [sym__fingerprints_option] = sym__fingerprints_option,
  [sym__state_policy_option] = sym__state_policy_option,
  [sym__debug_option] = sym__debug_option,
  [sym__skip_option] = sym__skip_option,
  [sym__state_defaults_option] = sym__state_defaults_option,
  [sym__keep_counters_option] = sym__keep_counters_option,
  [sym__syncookies_option] = sym__syncookies_option,
  [sym_optimization_hint] = sym_optimization_hint,
  [sym_ruleset_optimizer] = sym_ruleset_optimizer,
  [sym_timeout_list] = sym_timeout_list,
  [sym_timeout_spec] = sym_timeout_spec,
  [sym_timeout_type] = sym_timeout_type,
  [sym_limit_list] = sym_limit_list,
  [sym_limit_spec] = sym_limit_spec,
  [sym_ifspec] = sym_ifspec,
  [sym_interface_list] = sym_interface_list,
  [sym_interface] = sym_interface,
  [sym_state_opt_list] = sym_state_opt_list,
  [sym_state_opt] = sym_state_opt,
  [sym_string] = sym_string,
  [sym_floating_keyword] = sym_floating_keyword,
  [sym_if_bound_keyword] = sym_if_bound_keyword,
  [sym_no_keyword] = sym_no_keyword,
  [sym_yes_keyword] = sym_yes_keyword,
  [aux_sym_lines_repeat1] = aux_sym_lines_repeat1,
  [aux_sym_timeout_list_repeat1] = aux_sym_timeout_list_repeat1,
  [aux_sym_limit_list_repeat1] = aux_sym_limit_list_repeat1,
  [aux_sym_interface_list_repeat1] = aux_sym_interface_list_repeat1,
  [aux_sym_state_opt_list_repeat1] = aux_sym_state_opt_list_repeat1,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [sym_identifier] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_POUND] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_comment_token1] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_LBRACE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RBRACE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_none] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_yes] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_no] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_if_DASHbound] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_floating] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_urgent] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_misc] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_loud] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_never] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_adaptative] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_always] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_normal] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_satellite] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_high_DASHlatency] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_conservative] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_aggressive] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_basic] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_profile] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_COMMA] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_tcp_DOTfirst] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_tcp_DOTopening] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_tcp_DOTestablished] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_tcp_DOTclosing] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_tcp_DOTfinwait] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_tcp_DOTclosed] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_tcp_DOTtsdiff] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_sctp_DOTopening] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_sctp_DOTestablished] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_sctp_DOTclosing] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_sctp_DOTclosed] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_udp_DOTfirst] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_udp_DOTsingle] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_udp_DOTmultiple] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_icmp_DOTfirst] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_icmp_DOTerror] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_other_DOTfirst] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_other_DOTsingle] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_other_DOTmultiple] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_frag] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_interval] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_adaptive_DOTstart] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_adaptive_DOTend] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_src_DOTtrack] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_states] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_src_DASHnodes] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_frags] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_table_DASHentries] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_SLASH] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_GT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DQUOTE] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_string_token1] = {
    .visible = false,
    .named = false,
  },
  [sym_number] = {
    .visible = true,
    .named = true,
  },
  [sym_hex_number] = {
    .visible = true,
    .named = true,
  },
  [sym_not_operator] = {
    .visible = true,
    .named = true,
  },
  [sym_all_keyword] = {
    .visible = true,
    .named = true,
  },
  [sym_allow_opts_keyword] = {
    .visible = true,
    .named = true,
  },
  [sym_altq_keyword] = {
    .visible = true,
    .named = true,
  },
  [sym_anchor_keyword] = {
    .visible = true,
    .named = true,
  },
  [sym_antispoof_keyword] = {
    .visible = true,
    .named = true,
  },
  [sym_any_keyword] = {
    .visible = true,
    .named = true,
  },
  [sym_bandwidth_keyword] = {
    .visible = true,
    .named = true,
  },
  [sym_binat_keyword] = {
    .visible = true,
    .named = true,
  },
  [sym_binat_anchor_keyword] = {
    .visible = true,
    .named = true,
  },
  [sym_bitmask_keyword] = {
    .visible = true,
    .named = true,
  },
  [sym_block_keyword] = {
    .visible = true,
    .named = true,
  },
  [sym_block_policy_keyword] = {
    .visible = true,
    .named = true,
  },
  [sym_bridge_to_keyword] = {
    .visible = true,
    .named = true,
  },
  [sym_buckets_keyword] = {
    .visible = true,
    .named = true,
  },
  [sym_cbq_keyword] = {
    .visible = true,
    .named = true,
  },
  [sym_code_keyword] = {
    .visible = true,
    .named = true,
  },
  [sym_codelq_keyword] = {
    .visible = true,
    .named = true,
  },
  [sym_debug_keyword] = {
    .visible = true,
    .named = true,
  },
  [sym_divert_reply_keyword] = {
    .visible = true,
    .named = true,
  },
  [sym_divert_to_keyword] = {
    .visible = true,
    .named = true,
  },
  [sym_dnpipe_keyword] = {
    .visible = true,
    .named = true,
  },
  [sym_dnqueue_keyword] = {
    .visible = true,
    .named = true,
  },
  [sym_drop_keyword] = {
    .visible = true,
    .named = true,
  },
  [sym_dup_to_keyword] = {
    .visible = true,
    .named = true,
  },
  [sym_ether_keyword] = {
    .visible = true,
    .named = true,
  },
  [sym_fail_policy_keyword] = {
    .visible = true,
    .named = true,
  },
  [sym_fairq_keyword] = {
    .visible = true,
    .named = true,
  },
  [sym_fastroute_keyword] = {
    .visible = true,
    .named = true,
  },
  [sym_file_keyword] = {
    .visible = true,
    .named = true,
  },
  [sym_fingerprints_keyword] = {
    .visible = true,
    .named = true,
  },
  [sym_flags_keyword] = {
    .visible = true,
    .named = true,
  },
  [sym_flush_keyword] = {
    .visible = true,
    .named = true,
  },
  [sym_for_keyword] = {
    .visible = true,
    .named = true,
  },
  [sym_fragment_keyword] = {
    .visible = true,
    .named = true,
  },
  [sym_from_keyword] = {
    .visible = true,
    .named = true,
  },
  [sym_global_keyword] = {
    .visible = true,
    .named = true,
  },
  [sym_group_keyword] = {
    .visible = true,
    .named = true,
  },
  [sym_hfsc_keyword] = {
    .visible = true,
    .named = true,
  },
  [sym_hogs_keyword] = {
    .visible = true,
    .named = true,
  },
  [sym_hostid_keyword] = {
    .visible = true,
    .named = true,
  },
  [sym_icmp_type_keyword] = {
    .visible = true,
    .named = true,
  },
  [sym_icmp6_type_keyword] = {
    .visible = true,
    .named = true,
  },
  [sym_in_keyword] = {
    .visible = true,
    .named = true,
  },
  [sym_include_keyword] = {
    .visible = true,
    .named = true,
  },
  [sym_inet_keyword] = {
    .visible = true,
    .named = true,
  },
  [sym_inet6_keyword] = {
    .visible = true,
    .named = true,
  },
  [sym_keep_keyword] = {
    .visible = true,
    .named = true,
  },
  [sym_keepcounters_keyword] = {
    .visible = true,
    .named = true,
  },
  [sym_l3_keyword] = {
    .visible = true,
    .named = true,
  },
  [sym_label_keyword] = {
    .visible = true,
    .named = true,
  },
  [sym_limit_keyword] = {
    .visible = true,
    .named = true,
  },
  [sym_linkshare_keyword] = {
    .visible = true,
    .named = true,
  },
  [sym_load_keyword] = {
    .visible = true,
    .named = true,
  },
  [sym_log_keyword] = {
    .visible = true,
    .named = true,
  },
  [sym_loginterface_keyword] = {
    .visible = true,
    .named = true,
  },
  [sym_map_e_portset_keyword] = {
    .visible = true,
    .named = true,
  },
  [sym_match_keyword] = {
    .visible = true,
    .named = true,
  },
  [sym_max_keyword] = {
    .visible = true,
    .named = true,
  },
  [sym_max_mss_keyword] = {
    .visible = true,
    .named = true,
  },
  [sym_max_src_conn_keyword] = {
    .visible = true,
    .named = true,
  },
  [sym_max_src_conn_rate_keyword] = {
    .visible = true,
    .named = true,
  },
  [sym_max_src_nodes_keyword] = {
    .visible = true,
    .named = true,
  },
  [sym_max_src_states_keyword] = {
    .visible = true,
    .named = true,
  },
  [sym_min_ttl_keyword] = {
    .visible = true,
    .named = true,
  },
  [sym_modulate_keyword] = {
    .visible = true,
    .named = true,
  },
  [sym_nat_keyword] = {
    .visible = true,
    .named = true,
  },
  [sym_nat_anchor_keyword] = {
    .visible = true,
    .named = true,
  },
  [sym_no_df_keyword] = {
    .visible = true,
    .named = true,
  },
  [sym_no_route_keyword] = {
    .visible = true,
    .named = true,
  },
  [sym_no_sync_keyword] = {
    .visible = true,
    .named = true,
  },
  [sym_on_keyword] = {
    .visible = true,
    .named = true,
  },
  [sym_optimization_keyword] = {
    .visible = true,
    .named = true,
  },
  [sym_os_keyword] = {
    .visible = true,
    .named = true,
  },
  [sym_out_keyword] = {
    .visible = true,
    .named = true,
  },
  [sym_overload_keyword] = {
    .visible = true,
    .named = true,
  },
  [sym_pass_keyword] = {
    .visible = true,
    .named = true,
  },
  [sym_pflow_keyword] = {
    .visible = true,
    .named = true,
  },
  [sym_port_keyword] = {
    .visible = true,
    .named = true,
  },
  [sym_prio_keyword] = {
    .visible = true,
    .named = true,
  },
  [sym_priority_keyword] = {
    .visible = true,
    .named = true,
  },
  [sym_priq_keyword] = {
    .visible = true,
    .named = true,
  },
  [sym_probability_keyword] = {
    .visible = true,
    .named = true,
  },
  [sym_proto_keyword] = {
    .visible = true,
    .named = true,
  },
  [sym_qlimit_keyword] = {
    .visible = true,
    .named = true,
  },
  [sym_queue_keyword] = {
    .visible = true,
    .named = true,
  },
  [sym_quick_keyword] = {
    .visible = true,
    .named = true,
  },
  [sym_random_keyword] = {
    .visible = true,
    .named = true,
  },
  [sym_random_id_keyword] = {
    .visible = true,
    .named = true,
  },
  [sym_rdr_keyword] = {
    .visible = true,
    .named = true,
  },
  [sym_rdr_anchor_keyword] = {
    .visible = true,
    .named = true,
  },
  [sym_realtime_keyword] = {
    .visible = true,
    .named = true,
  },
  [sym_reassemble_keyword] = {
    .visible = true,
    .named = true,
  },
  [sym_reply_to_keyword] = {
    .visible = true,
    .named = true,
  },
  [sym_require_order_keyword] = {
    .visible = true,
    .named = true,
  },
  [sym_return_keyword] = {
    .visible = true,
    .named = true,
  },
  [sym_return_icmp_keyword] = {
    .visible = true,
    .named = true,
  },
  [sym_return_icmp6_keyword] = {
    .visible = true,
    .named = true,
  },
  [sym_return_rst_keyword] = {
    .visible = true,
    .named = true,
  },
  [sym_ridentifier_keyword] = {
    .visible = true,
    .named = true,
  },
  [sym_round_robin_keyword] = {
    .visible = true,
    .named = true,
  },
  [sym_route_keyword] = {
    .visible = true,
    .named = true,
  },
  [sym_route_to_keyword] = {
    .visible = true,
    .named = true,
  },
  [sym_rtable_keyword] = {
    .visible = true,
    .named = true,
  },
  [sym_rule_keyword] = {
    .visible = true,
    .named = true,
  },
  [sym_ruleset_optimization_keyword] = {
    .visible = true,
    .named = true,
  },
  [sym_scrub_keyword] = {
    .visible = true,
    .named = true,
  },
  [sym_self_keyword] = {
    .visible = true,
    .named = true,
  },
  [sym_set_keyword] = {
    .visible = true,
    .named = true,
  },
  [sym_set_tos_keyword] = {
    .visible = true,
    .named = true,
  },
  [sym_skip_keyword] = {
    .visible = true,
    .named = true,
  },
  [sym_sloppy_keyword] = {
    .visible = true,
    .named = true,
  },
  [sym_source_hash_keyword] = {
    .visible = true,
    .named = true,
  },
  [sym_source_track_keyword] = {
    .visible = true,
    .named = true,
  },
  [sym_state_keyword] = {
    .visible = true,
    .named = true,
  },
  [sym_state_defaults_keyword] = {
    .visible = true,
    .named = true,
  },
  [sym_state_policy_keyword] = {
    .visible = true,
    .named = true,
  },
  [sym_static_port_keyword] = {
    .visible = true,
    .named = true,
  },
  [sym_sticky_address_keyword] = {
    .visible = true,
    .named = true,
  },
  [sym_syncookies_keyword] = {
    .visible = true,
    .named = true,
  },
  [sym_synproxy_keyword] = {
    .visible = true,
    .named = true,
  },
  [sym_table_keyword] = {
    .visible = true,
    .named = true,
  },
  [sym_tag_keyword] = {
    .visible = true,
    .named = true,
  },
  [sym_tagged_keyword] = {
    .visible = true,
    .named = true,
  },
  [sym_target_keyword] = {
    .visible = true,
    .named = true,
  },
  [sym_tbrsize_keyword] = {
    .visible = true,
    .named = true,
  },
  [sym_timeout_keyword] = {
    .visible = true,
    .named = true,
  },
  [sym_to_keyword] = {
    .visible = true,
    .named = true,
  },
  [sym_tos_keyword] = {
    .visible = true,
    .named = true,
  },
  [sym_ttl_keyword] = {
    .visible = true,
    .named = true,
  },
  [sym_upperlimit_keyword] = {
    .visible = true,
    .named = true,
  },
  [sym_urpf_failed_keyword] = {
    .visible = true,
    .named = true,
  },
  [sym_user_keyword] = {
    .visible = true,
    .named = true,
  },
  [sym_lines] = {
    .visible = true,
    .named = true,
  },
  [sym_line] = {
    .visible = true,
    .named = true,
  },
  [sym_comment] = {
    .visible = true,
    .named = true,
  },
  [sym_option] = {
    .visible = true,
    .named = true,
  },
  [sym__reassemble_option] = {
    .visible = false,
    .named = true,
  },
  [sym__optimization_option] = {
    .visible = false,
    .named = true,
  },
  [sym__ruleset_optimization_option] = {
    .visible = false,
    .named = true,
  },
  [sym__timeout_option] = {
    .visible = false,
    .named = true,
  },
  [sym__limit_option] = {
    .visible = false,
    .named = true,
  },
  [sym__loginterface_option] = {
    .visible = false,
    .named = true,
  },
  [sym__hostid_option] = {
    .visible = false,
    .named = true,
  },
  [sym__block_policy_option] = {
    .visible = false,
    .named = true,
  },
  [sym__fail_policy_option] = {
    .visible = false,
    .named = true,
  },
  [sym__require_order_option] = {
    .visible = false,
    .named = true,
  },
  [sym__fingerprints_option] = {
    .visible = false,
    .named = true,
  },
  [sym__state_policy_option] = {
    .visible = false,
    .named = true,
  },
  [sym__debug_option] = {
    .visible = false,
    .named = true,
  },
  [sym__skip_option] = {
    .visible = false,
    .named = true,
  },
  [sym__state_defaults_option] = {
    .visible = false,
    .named = true,
  },
  [sym__keep_counters_option] = {
    .visible = false,
    .named = true,
  },
  [sym__syncookies_option] = {
    .visible = false,
    .named = true,
  },
  [sym_optimization_hint] = {
    .visible = true,
    .named = true,
  },
  [sym_ruleset_optimizer] = {
    .visible = true,
    .named = true,
  },
  [sym_timeout_list] = {
    .visible = true,
    .named = true,
  },
  [sym_timeout_spec] = {
    .visible = true,
    .named = true,
  },
  [sym_timeout_type] = {
    .visible = true,
    .named = true,
  },
  [sym_limit_list] = {
    .visible = true,
    .named = true,
  },
  [sym_limit_spec] = {
    .visible = true,
    .named = true,
  },
  [sym_ifspec] = {
    .visible = true,
    .named = true,
  },
  [sym_interface_list] = {
    .visible = true,
    .named = true,
  },
  [sym_interface] = {
    .visible = true,
    .named = true,
  },
  [sym_state_opt_list] = {
    .visible = true,
    .named = true,
  },
  [sym_state_opt] = {
    .visible = true,
    .named = true,
  },
  [sym_string] = {
    .visible = true,
    .named = true,
  },
  [sym_floating_keyword] = {
    .visible = true,
    .named = true,
  },
  [sym_if_bound_keyword] = {
    .visible = true,
    .named = true,
  },
  [sym_no_keyword] = {
    .visible = true,
    .named = true,
  },
  [sym_yes_keyword] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_lines_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_timeout_list_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_limit_list_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_interface_list_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_state_opt_list_repeat1] = {
    .visible = false,
    .named = false,
  },
};

enum ts_field_identifiers {
  field_filename = 1,
  field_hint = 2,
  field_interface = 3,
  field_number = 4,
  field_optimizer = 5,
  field_string = 6,
};

static const char * const ts_field_names[] = {
  [0] = NULL,
  [field_filename] = "filename",
  [field_hint] = "hint",
  [field_interface] = "interface",
  [field_number] = "number",
  [field_optimizer] = "optimizer",
  [field_string] = "string",
};

static const TSFieldMapSlice ts_field_map_slices[PRODUCTION_ID_COUNT] = {
  [1] = {.index = 0, .length = 1},
  [2] = {.index = 1, .length = 1},
  [3] = {.index = 2, .length = 1},
  [4] = {.index = 3, .length = 1},
  [5] = {.index = 4, .length = 1},
  [6] = {.index = 5, .length = 1},
  [7] = {.index = 6, .length = 1},
  [8] = {.index = 7, .length = 1},
  [9] = {.index = 8, .length = 1},
  [10] = {.index = 9, .length = 1},
  [11] = {.index = 10, .length = 1},
  [12] = {.index = 11, .length = 2},
  [13] = {.index = 13, .length = 1},
};

static const TSFieldMapEntry ts_field_map_entries[] = {
  [0] =
    {field_hint, 1, .inherited = true},
  [1] =
    {field_optimizer, 1, .inherited = true},
  [2] =
    {field_interface, 1, .inherited = true},
  [3] =
    {field_number, 1, .inherited = true},
  [4] =
    {field_filename, 1, .inherited = true},
  [5] =
    {field_filename, 1},
  [6] =
    {field_number, 1},
  [7] =
    {field_interface, 1},
  [8] =
    {field_hint, 1},
  [9] =
    {field_optimizer, 1},
  [10] =
    {field_interface, 0},
  [11] =
    {field_number, 1},
    {field_number, 3},
  [13] =
    {field_string, 2},
};

static const TSSymbol ts_alias_sequences[PRODUCTION_ID_COUNT][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
};

static const uint16_t ts_non_terminal_alias_map[] = {
  0,
};

static const TSStateId ts_primary_state_ids[STATE_COUNT] = {
  [0] = 0,
  [1] = 1,
  [2] = 2,
  [3] = 3,
  [4] = 4,
  [5] = 5,
  [6] = 6,
  [7] = 7,
  [8] = 8,
  [9] = 9,
  [10] = 10,
  [11] = 11,
  [12] = 12,
  [13] = 13,
  [14] = 14,
  [15] = 15,
  [16] = 16,
  [17] = 17,
  [18] = 18,
  [19] = 19,
  [20] = 20,
  [21] = 21,
  [22] = 22,
  [23] = 23,
  [24] = 24,
  [25] = 25,
  [26] = 26,
  [27] = 27,
  [28] = 28,
  [29] = 29,
  [30] = 30,
  [31] = 31,
  [32] = 32,
  [33] = 33,
  [34] = 34,
  [35] = 35,
  [36] = 36,
  [37] = 37,
  [38] = 38,
  [39] = 39,
  [40] = 40,
  [41] = 41,
  [42] = 42,
  [43] = 43,
  [44] = 44,
  [45] = 45,
  [46] = 46,
  [47] = 47,
  [48] = 48,
  [49] = 49,
  [50] = 50,
  [51] = 51,
  [52] = 52,
  [53] = 53,
  [54] = 54,
  [55] = 55,
  [56] = 56,
  [57] = 57,
  [58] = 58,
  [59] = 59,
  [60] = 60,
  [61] = 61,
  [62] = 62,
  [63] = 63,
  [64] = 64,
  [65] = 65,
  [66] = 66,
  [67] = 67,
  [68] = 68,
  [69] = 69,
  [70] = 70,
  [71] = 71,
  [72] = 72,
  [73] = 73,
  [74] = 74,
  [75] = 75,
  [76] = 76,
  [77] = 77,
  [78] = 78,
  [79] = 79,
  [80] = 80,
  [81] = 81,
  [82] = 82,
  [83] = 83,
  [84] = 84,
  [85] = 85,
  [86] = 86,
  [87] = 87,
  [88] = 88,
  [89] = 89,
  [90] = 90,
  [91] = 91,
  [92] = 92,
  [93] = 93,
  [94] = 94,
  [95] = 95,
  [96] = 96,
  [97] = 97,
  [98] = 98,
  [99] = 99,
  [100] = 100,
  [101] = 101,
  [102] = 102,
  [103] = 103,
  [104] = 104,
  [105] = 105,
  [106] = 106,
  [107] = 107,
  [108] = 108,
  [109] = 109,
  [110] = 110,
  [111] = 111,
  [112] = 112,
};

static inline bool sym_identifier_character_set_1(int32_t c) {
  return (c < 43514
    ? (c < 4193
      ? (c < 2707
        ? (c < 1994
          ? (c < 910
            ? (c < 736
              ? (c < 186
                ? (c < 'c'
                  ? (c < '_'
                    ? (c >= 'A' && c <= 'Z')
                    : c <= '_')
                  : (c <= 'z' || (c < 181
                    ? c == 170
                    : c <= 181)))
                : (c <= 186 || (c < 248
                  ? (c < 216
                    ? (c >= 192 && c <= 214)
                    : c <= 246)
                  : (c <= 705 || (c >= 710 && c <= 721)))))
              : (c <= 740 || (c < 891
                ? (c < 880
                  ? (c < 750
                    ? c == 748
                    : c <= 750)
                  : (c <= 884 || (c >= 886 && c <= 887)))
                : (c <= 893 || (c < 904
                  ? (c < 902
                    ? c == 895
                    : c <= 902)
                  : (c <= 906 || c == 908))))))
            : (c <= 929 || (c < 1649
              ? (c < 1376
                ? (c < 1162
                  ? (c < 1015
                    ? (c >= 931 && c <= 1013)
                    : c <= 1153)
                  : (c <= 1327 || (c < 1369
                    ? (c >= 1329 && c <= 1366)
                    : c <= 1369)))
                : (c <= 1416 || (c < 1568
                  ? (c < 1519
                    ? (c >= 1488 && c <= 1514)
                    : c <= 1522)
                  : (c <= 1610 || (c >= 1646 && c <= 1647)))))
              : (c <= 1747 || (c < 1791
                ? (c < 1774
                  ? (c < 1765
                    ? c == 1749
                    : c <= 1766)
                  : (c <= 1775 || (c >= 1786 && c <= 1788)))
                : (c <= 1791 || (c < 1869
                  ? (c < 1810
                    ? c == 1808
                    : c <= 1839)
                  : (c <= 1957 || c == 1969))))))))
          : (c <= 2026 || (c < 2482
            ? (c < 2208
              ? (c < 2088
                ? (c < 2048
                  ? (c < 2042
                    ? (c >= 2036 && c <= 2037)
                    : c <= 2042)
                  : (c <= 2069 || (c < 2084
                    ? c == 2074
                    : c <= 2084)))
                : (c <= 2088 || (c < 2160
                  ? (c < 2144
                    ? (c >= 2112 && c <= 2136)
                    : c <= 2154)
                  : (c <= 2183 || (c >= 2185 && c <= 2190)))))
              : (c <= 2249 || (c < 2417
                ? (c < 2384
                  ? (c < 2365
                    ? (c >= 2308 && c <= 2361)
                    : c <= 2365)
                  : (c <= 2384 || (c >= 2392 && c <= 2401)))
                : (c <= 2432 || (c < 2451
                  ? (c < 2447
                    ? (c >= 2437 && c <= 2444)
                    : c <= 2448)
                  : (c <= 2472 || (c >= 2474 && c <= 2480)))))))
            : (c <= 2482 || (c < 2579
              ? (c < 2527
                ? (c < 2510
                  ? (c < 2493
                    ? (c >= 2486 && c <= 2489)
                    : c <= 2493)
                  : (c <= 2510 || (c >= 2524 && c <= 2525)))
                : (c <= 2529 || (c < 2565
                  ? (c < 2556
                    ? (c >= 2544 && c <= 2545)
                    : c <= 2556)
                  : (c <= 2570 || (c >= 2575 && c <= 2576)))))
              : (c <= 2600 || (c < 2649
                ? (c < 2613
                  ? (c < 2610
                    ? (c >= 2602 && c <= 2608)
                    : c <= 2611)
                  : (c <= 2614 || (c >= 2616 && c <= 2617)))
                : (c <= 2652 || (c < 2693
                  ? (c < 2674
                    ? c == 2654
                    : c <= 2676)
                  : (c <= 2701 || (c >= 2703 && c <= 2705)))))))))))
        : (c <= 2728 || (c < 3242
          ? (c < 2962
            ? (c < 2858
              ? (c < 2784
                ? (c < 2741
                  ? (c < 2738
                    ? (c >= 2730 && c <= 2736)
                    : c <= 2739)
                  : (c <= 2745 || (c < 2768
                    ? c == 2749
                    : c <= 2768)))
                : (c <= 2785 || (c < 2831
                  ? (c < 2821
                    ? c == 2809
                    : c <= 2828)
                  : (c <= 2832 || (c >= 2835 && c <= 2856)))))
              : (c <= 2864 || (c < 2911
                ? (c < 2877
                  ? (c < 2869
                    ? (c >= 2866 && c <= 2867)
                    : c <= 2873)
                  : (c <= 2877 || (c >= 2908 && c <= 2909)))
                : (c <= 2913 || (c < 2949
                  ? (c < 2947
                    ? c == 2929
                    : c <= 2947)
                  : (c <= 2954 || (c >= 2958 && c <= 2960)))))))
            : (c <= 2965 || (c < 3090
              ? (c < 2984
                ? (c < 2974
                  ? (c < 2972
                    ? (c >= 2969 && c <= 2970)
                    : c <= 2972)
                  : (c <= 2975 || (c >= 2979 && c <= 2980)))
                : (c <= 2986 || (c < 3077
                  ? (c < 3024
                    ? (c >= 2990 && c <= 3001)
                    : c <= 3024)
                  : (c <= 3084 || (c >= 3086 && c <= 3088)))))
              : (c <= 3112 || (c < 3168
                ? (c < 3160
                  ? (c < 3133
                    ? (c >= 3114 && c <= 3129)
                    : c <= 3133)
                  : (c <= 3162 || c == 3165))
                : (c <= 3169 || (c < 3214
                  ? (c < 3205
                    ? c == 3200
                    : c <= 3212)
                  : (c <= 3216 || (c >= 3218 && c <= 3240)))))))))
          : (c <= 3251 || (c < 3648
            ? (c < 3412
              ? (c < 3332
                ? (c < 3293
                  ? (c < 3261
                    ? (c >= 3253 && c <= 3257)
                    : c <= 3261)
                  : (c <= 3294 || (c < 3313
                    ? (c >= 3296 && c <= 3297)
                    : c <= 3314)))
                : (c <= 3340 || (c < 3389
                  ? (c < 3346
                    ? (c >= 3342 && c <= 3344)
                    : c <= 3386)
                  : (c <= 3389 || c == 3406))))
              : (c <= 3414 || (c < 3507
                ? (c < 3461
                  ? (c < 3450
                    ? (c >= 3423 && c <= 3425)
                    : c <= 3455)
                  : (c <= 3478 || (c >= 3482 && c <= 3505)))
                : (c <= 3515 || (c < 3585
                  ? (c < 3520
                    ? c == 3517
                    : c <= 3526)
                  : (c <= 3632 || c == 3634))))))
            : (c <= 3654 || (c < 3782
              ? (c < 3749
                ? (c < 3718
                  ? (c < 3716
                    ? (c >= 3713 && c <= 3714)
                    : c <= 3716)
                  : (c <= 3722 || (c >= 3724 && c <= 3747)))
                : (c <= 3749 || (c < 3773
                  ? (c < 3762
                    ? (c >= 3751 && c <= 3760)
                    : c <= 3762)
                  : (c <= 3773 || (c >= 3776 && c <= 3780)))))
              : (c <= 3782 || (c < 3976
                ? (c < 3904
                  ? (c < 3840
                    ? (c >= 3804 && c <= 3807)
                    : c <= 3840)
                  : (c <= 3911 || (c >= 3913 && c <= 3948)))
                : (c <= 3980 || (c < 4176
                  ? (c < 4159
                    ? (c >= 4096 && c <= 4138)
                    : c <= 4159)
                  : (c <= 4181 || (c >= 4186 && c <= 4189)))))))))))))
      : (c <= 4193 || (c < 8134
        ? (c < 6176
          ? (c < 4808
            ? (c < 4688
              ? (c < 4295
                ? (c < 4213
                  ? (c < 4206
                    ? (c >= 4197 && c <= 4198)
                    : c <= 4208)
                  : (c <= 4225 || (c < 4256
                    ? c == 4238
                    : c <= 4293)))
                : (c <= 4295 || (c < 4348
                  ? (c < 4304
                    ? c == 4301
                    : c <= 4346)
                  : (c <= 4680 || (c >= 4682 && c <= 4685)))))
              : (c <= 4694 || (c < 4752
                ? (c < 4704
                  ? (c < 4698
                    ? c == 4696
                    : c <= 4701)
                  : (c <= 4744 || (c >= 4746 && c <= 4749)))
                : (c <= 4784 || (c < 4800
                  ? (c < 4792
                    ? (c >= 4786 && c <= 4789)
                    : c <= 4798)
                  : (c <= 4800 || (c >= 4802 && c <= 4805)))))))
            : (c <= 4822 || (c < 5792
              ? (c < 5024
                ? (c < 4888
                  ? (c < 4882
                    ? (c >= 4824 && c <= 4880)
                    : c <= 4885)
                  : (c <= 4954 || (c >= 4992 && c <= 5007)))
                : (c <= 5109 || (c < 5743
                  ? (c < 5121
                    ? (c >= 5112 && c <= 5117)
                    : c <= 5740)
                  : (c <= 5759 || (c >= 5761 && c <= 5786)))))
              : (c <= 5866 || (c < 5984
                ? (c < 5919
                  ? (c < 5888
                    ? (c >= 5870 && c <= 5880)
                    : c <= 5905)
                  : (c <= 5937 || (c >= 5952 && c <= 5969)))
                : (c <= 5996 || (c < 6103
                  ? (c < 6016
                    ? (c >= 5998 && c <= 6000)
                    : c <= 6067)
                  : (c <= 6103 || c == 6108))))))))
          : (c <= 6264 || (c < 7312
            ? (c < 6823
              ? (c < 6512
                ? (c < 6320
                  ? (c < 6314
                    ? (c >= 6272 && c <= 6312)
                    : c <= 6314)
                  : (c <= 6389 || (c < 6480
                    ? (c >= 6400 && c <= 6430)
                    : c <= 6509)))
                : (c <= 6516 || (c < 6656
                  ? (c < 6576
                    ? (c >= 6528 && c <= 6571)
                    : c <= 6601)
                  : (c <= 6678 || (c >= 6688 && c <= 6740)))))
              : (c <= 6823 || (c < 7098
                ? (c < 7043
                  ? (c < 6981
                    ? (c >= 6917 && c <= 6963)
                    : c <= 6988)
                  : (c <= 7072 || (c >= 7086 && c <= 7087)))
                : (c <= 7141 || (c < 7258
                  ? (c < 7245
                    ? (c >= 7168 && c <= 7203)
                    : c <= 7247)
                  : (c <= 7293 || (c >= 7296 && c <= 7304)))))))
            : (c <= 7354 || (c < 8008
              ? (c < 7418
                ? (c < 7406
                  ? (c < 7401
                    ? (c >= 7357 && c <= 7359)
                    : c <= 7404)
                  : (c <= 7411 || (c >= 7413 && c <= 7414)))
                : (c <= 7418 || (c < 7960
                  ? (c < 7680
                    ? (c >= 7424 && c <= 7615)
                    : c <= 7957)
                  : (c <= 7965 || (c >= 7968 && c <= 8005)))))
              : (c <= 8013 || (c < 8031
                ? (c < 8027
                  ? (c < 8025
                    ? (c >= 8016 && c <= 8023)
                    : c <= 8025)
                  : (c <= 8027 || c == 8029))
                : (c <= 8061 || (c < 8126
                  ? (c < 8118
                    ? (c >= 8064 && c <= 8116)
                    : c <= 8124)
                  : (c <= 8126 || (c >= 8130 && c <= 8132)))))))))))
        : (c <= 8140 || (c < 12337
          ? (c < 8544
            ? (c < 8458
              ? (c < 8305
                ? (c < 8160
                  ? (c < 8150
                    ? (c >= 8144 && c <= 8147)
                    : c <= 8155)
                  : (c <= 8172 || (c < 8182
                    ? (c >= 8178 && c <= 8180)
                    : c <= 8188)))
                : (c <= 8305 || (c < 8450
                  ? (c < 8336
                    ? c == 8319
                    : c <= 8348)
                  : (c <= 8450 || c == 8455))))
              : (c <= 8467 || (c < 8488
                ? (c < 8484
                  ? (c < 8472
                    ? c == 8469
                    : c <= 8477)
                  : (c <= 8484 || c == 8486))
                : (c <= 8488 || (c < 8517
                  ? (c < 8508
                    ? (c >= 8490 && c <= 8505)
                    : c <= 8511)
                  : (c <= 8521 || c == 8526))))))
            : (c <= 8584 || (c < 11680
              ? (c < 11559
                ? (c < 11506
                  ? (c < 11499
                    ? (c >= 11264 && c <= 11492)
                    : c <= 11502)
                  : (c <= 11507 || (c >= 11520 && c <= 11557)))
                : (c <= 11559 || (c < 11631
                  ? (c < 11568
                    ? c == 11565
                    : c <= 11623)
                  : (c <= 11631 || (c >= 11648 && c <= 11670)))))
              : (c <= 11686 || (c < 11720
                ? (c < 11704
                  ? (c < 11696
                    ? (c >= 11688 && c <= 11694)
                    : c <= 11702)
                  : (c <= 11710 || (c >= 11712 && c <= 11718)))
                : (c <= 11726 || (c < 12293
                  ? (c < 11736
                    ? (c >= 11728 && c <= 11734)
                    : c <= 11742)
                  : (c <= 12295 || (c >= 12321 && c <= 12329)))))))))
          : (c <= 12341 || (c < 42891
            ? (c < 19968
              ? (c < 12549
                ? (c < 12445
                  ? (c < 12353
                    ? (c >= 12344 && c <= 12348)
                    : c <= 12438)
                  : (c <= 12447 || (c < 12540
                    ? (c >= 12449 && c <= 12538)
                    : c <= 12543)))
                : (c <= 12591 || (c < 12784
                  ? (c < 12704
                    ? (c >= 12593 && c <= 12686)
                    : c <= 12735)
                  : (c <= 12799 || (c >= 13312 && c <= 19903)))))
              : (c <= 42124 || (c < 42560
                ? (c < 42512
                  ? (c < 42240
                    ? (c >= 42192 && c <= 42237)
                    : c <= 42508)
                  : (c <= 42527 || (c >= 42538 && c <= 42539)))
                : (c <= 42606 || (c < 42775
                  ? (c < 42656
                    ? (c >= 42623 && c <= 42653)
                    : c <= 42735)
                  : (c <= 42783 || (c >= 42786 && c <= 42888)))))))
            : (c <= 42954 || (c < 43250
              ? (c < 43011
                ? (c < 42965
                  ? (c < 42963
                    ? (c >= 42960 && c <= 42961)
                    : c <= 42963)
                  : (c <= 42969 || (c >= 42994 && c <= 43009)))
                : (c <= 43013 || (c < 43072
                  ? (c < 43020
                    ? (c >= 43015 && c <= 43018)
                    : c <= 43042)
                  : (c <= 43123 || (c >= 43138 && c <= 43187)))))
              : (c <= 43255 || (c < 43360
                ? (c < 43274
                  ? (c < 43261
                    ? c == 43259
                    : c <= 43262)
                  : (c <= 43301 || (c >= 43312 && c <= 43334)))
                : (c <= 43388 || (c < 43488
                  ? (c < 43471
                    ? (c >= 43396 && c <= 43442)
                    : c <= 43471)
                  : (c <= 43492 || (c >= 43494 && c <= 43503)))))))))))))))
    : (c <= 43518 || (c < 70727
      ? (c < 66956
        ? (c < 64914
          ? (c < 43868
            ? (c < 43714
              ? (c < 43646
                ? (c < 43588
                  ? (c < 43584
                    ? (c >= 43520 && c <= 43560)
                    : c <= 43586)
                  : (c <= 43595 || (c < 43642
                    ? (c >= 43616 && c <= 43638)
                    : c <= 43642)))
                : (c <= 43695 || (c < 43705
                  ? (c < 43701
                    ? c == 43697
                    : c <= 43702)
                  : (c <= 43709 || c == 43712))))
              : (c <= 43714 || (c < 43785
                ? (c < 43762
                  ? (c < 43744
                    ? (c >= 43739 && c <= 43741)
                    : c <= 43754)
                  : (c <= 43764 || (c >= 43777 && c <= 43782)))
                : (c <= 43790 || (c < 43816
                  ? (c < 43808
                    ? (c >= 43793 && c <= 43798)
                    : c <= 43814)
                  : (c <= 43822 || (c >= 43824 && c <= 43866)))))))
            : (c <= 43881 || (c < 64287
              ? (c < 63744
                ? (c < 55216
                  ? (c < 44032
                    ? (c >= 43888 && c <= 44002)
                    : c <= 55203)
                  : (c <= 55238 || (c >= 55243 && c <= 55291)))
                : (c <= 64109 || (c < 64275
                  ? (c < 64256
                    ? (c >= 64112 && c <= 64217)
                    : c <= 64262)
                  : (c <= 64279 || c == 64285))))
              : (c <= 64296 || (c < 64323
                ? (c < 64318
                  ? (c < 64312
                    ? (c >= 64298 && c <= 64310)
                    : c <= 64316)
                  : (c <= 64318 || (c >= 64320 && c <= 64321)))
                : (c <= 64324 || (c < 64612
                  ? (c < 64467
                    ? (c >= 64326 && c <= 64433)
                    : c <= 64605)
                  : (c <= 64829 || (c >= 64848 && c <= 64911)))))))))
          : (c <= 64967 || (c < 65599
            ? (c < 65382
              ? (c < 65147
                ? (c < 65139
                  ? (c < 65137
                    ? (c >= 65008 && c <= 65017)
                    : c <= 65137)
                  : (c <= 65139 || (c < 65145
                    ? c == 65143
                    : c <= 65145)))
                : (c <= 65147 || (c < 65313
                  ? (c < 65151
                    ? c == 65149
                    : c <= 65276)
                  : (c <= 65338 || (c >= 65345 && c <= 65370)))))
              : (c <= 65437 || (c < 65498
                ? (c < 65482
                  ? (c < 65474
                    ? (c >= 65440 && c <= 65470)
                    : c <= 65479)
                  : (c <= 65487 || (c >= 65490 && c <= 65495)))
                : (c <= 65500 || (c < 65576
                  ? (c < 65549
                    ? (c >= 65536 && c <= 65547)
                    : c <= 65574)
                  : (c <= 65594 || (c >= 65596 && c <= 65597)))))))
            : (c <= 65613 || (c < 66464
              ? (c < 66208
                ? (c < 65856
                  ? (c < 65664
                    ? (c >= 65616 && c <= 65629)
                    : c <= 65786)
                  : (c <= 65908 || (c >= 66176 && c <= 66204)))
                : (c <= 66256 || (c < 66384
                  ? (c < 66349
                    ? (c >= 66304 && c <= 66335)
                    : c <= 66378)
                  : (c <= 66421 || (c >= 66432 && c <= 66461)))))
              : (c <= 66499 || (c < 66776
                ? (c < 66560
                  ? (c < 66513
                    ? (c >= 66504 && c <= 66511)
                    : c <= 66517)
                  : (c <= 66717 || (c >= 66736 && c <= 66771)))
                : (c <= 66811 || (c < 66928
                  ? (c < 66864
                    ? (c >= 66816 && c <= 66855)
                    : c <= 66915)
                  : (c <= 66938 || (c >= 66940 && c <= 66954)))))))))))
        : (c <= 66962 || (c < 68864
          ? (c < 67828
            ? (c < 67506
              ? (c < 67072
                ? (c < 66979
                  ? (c < 66967
                    ? (c >= 66964 && c <= 66965)
                    : c <= 66977)
                  : (c <= 66993 || (c < 67003
                    ? (c >= 66995 && c <= 67001)
                    : c <= 67004)))
                : (c <= 67382 || (c < 67456
                  ? (c < 67424
                    ? (c >= 67392 && c <= 67413)
                    : c <= 67431)
                  : (c <= 67461 || (c >= 67463 && c <= 67504)))))
              : (c <= 67514 || (c < 67644
                ? (c < 67594
                  ? (c < 67592
                    ? (c >= 67584 && c <= 67589)
                    : c <= 67592)
                  : (c <= 67637 || (c >= 67639 && c <= 67640)))
                : (c <= 67644 || (c < 67712
                  ? (c < 67680
                    ? (c >= 67647 && c <= 67669)
                    : c <= 67702)
                  : (c <= 67742 || (c >= 67808 && c <= 67826)))))))
            : (c <= 67829 || (c < 68224
              ? (c < 68096
                ? (c < 67968
                  ? (c < 67872
                    ? (c >= 67840 && c <= 67861)
                    : c <= 67897)
                  : (c <= 68023 || (c >= 68030 && c <= 68031)))
                : (c <= 68096 || (c < 68121
                  ? (c < 68117
                    ? (c >= 68112 && c <= 68115)
                    : c <= 68119)
                  : (c <= 68149 || (c >= 68192 && c <= 68220)))))
              : (c <= 68252 || (c < 68448
                ? (c < 68352
                  ? (c < 68297
                    ? (c >= 68288 && c <= 68295)
                    : c <= 68324)
                  : (c <= 68405 || (c >= 68416 && c <= 68437)))
                : (c <= 68466 || (c < 68736
                  ? (c < 68608
                    ? (c >= 68480 && c <= 68497)
                    : c <= 68680)
                  : (c <= 68786 || (c >= 68800 && c <= 68850)))))))))
          : (c <= 68899 || (c < 70106
            ? (c < 69749
              ? (c < 69488
                ? (c < 69376
                  ? (c < 69296
                    ? (c >= 69248 && c <= 69289)
                    : c <= 69297)
                  : (c <= 69404 || (c < 69424
                    ? c == 69415
                    : c <= 69445)))
                : (c <= 69505 || (c < 69635
                  ? (c < 69600
                    ? (c >= 69552 && c <= 69572)
                    : c <= 69622)
                  : (c <= 69687 || (c >= 69745 && c <= 69746)))))
              : (c <= 69749 || (c < 69959
                ? (c < 69891
                  ? (c < 69840
                    ? (c >= 69763 && c <= 69807)
                    : c <= 69864)
                  : (c <= 69926 || c == 69956))
                : (c <= 69959 || (c < 70019
                  ? (c < 70006
                    ? (c >= 69968 && c <= 70002)
                    : c <= 70006)
                  : (c <= 70066 || (c >= 70081 && c <= 70084)))))))
            : (c <= 70106 || (c < 70405
              ? (c < 70280
                ? (c < 70163
                  ? (c < 70144
                    ? c == 70108
                    : c <= 70161)
                  : (c <= 70187 || (c >= 70272 && c <= 70278)))
                : (c <= 70280 || (c < 70303
                  ? (c < 70287
                    ? (c >= 70282 && c <= 70285)
                    : c <= 70301)
                  : (c <= 70312 || (c >= 70320 && c <= 70366)))))
              : (c <= 70412 || (c < 70453
                ? (c < 70442
                  ? (c < 70419
                    ? (c >= 70415 && c <= 70416)
                    : c <= 70440)
                  : (c <= 70448 || (c >= 70450 && c <= 70451)))
                : (c <= 70457 || (c < 70493
                  ? (c < 70480
                    ? c == 70461
                    : c <= 70480)
                  : (c <= 70497 || (c >= 70656 && c <= 70708)))))))))))))
      : (c <= 70730 || (c < 119894
        ? (c < 73056
          ? (c < 72001
            ? (c < 71424
              ? (c < 71128
                ? (c < 70852
                  ? (c < 70784
                    ? (c >= 70751 && c <= 70753)
                    : c <= 70831)
                  : (c <= 70853 || (c < 71040
                    ? c == 70855
                    : c <= 71086)))
                : (c <= 71131 || (c < 71296
                  ? (c < 71236
                    ? (c >= 71168 && c <= 71215)
                    : c <= 71236)
                  : (c <= 71338 || c == 71352))))
              : (c <= 71450 || (c < 71945
                ? (c < 71840
                  ? (c < 71680
                    ? (c >= 71488 && c <= 71494)
                    : c <= 71723)
                  : (c <= 71903 || (c >= 71935 && c <= 71942)))
                : (c <= 71945 || (c < 71960
                  ? (c < 71957
                    ? (c >= 71948 && c <= 71955)
                    : c <= 71958)
                  : (c <= 71983 || c == 71999))))))
            : (c <= 72001 || (c < 72349
              ? (c < 72192
                ? (c < 72161
                  ? (c < 72106
                    ? (c >= 72096 && c <= 72103)
                    : c <= 72144)
                  : (c <= 72161 || c == 72163))
                : (c <= 72192 || (c < 72272
                  ? (c < 72250
                    ? (c >= 72203 && c <= 72242)
                    : c <= 72250)
                  : (c <= 72272 || (c >= 72284 && c <= 72329)))))
              : (c <= 72349 || (c < 72818
                ? (c < 72714
                  ? (c < 72704
                    ? (c >= 72368 && c <= 72440)
                    : c <= 72712)
                  : (c <= 72750 || c == 72768))
                : (c <= 72847 || (c < 72971
                  ? (c < 72968
                    ? (c >= 72960 && c <= 72966)
                    : c <= 72969)
                  : (c <= 73008 || c == 73030))))))))
          : (c <= 73061 || (c < 93952
            ? (c < 82944
              ? (c < 73728
                ? (c < 73112
                  ? (c < 73066
                    ? (c >= 73063 && c <= 73064)
                    : c <= 73097)
                  : (c <= 73112 || (c < 73648
                    ? (c >= 73440 && c <= 73458)
                    : c <= 73648)))
                : (c <= 74649 || (c < 77712
                  ? (c < 74880
                    ? (c >= 74752 && c <= 74862)
                    : c <= 75075)
                  : (c <= 77808 || (c >= 77824 && c <= 78894)))))
              : (c <= 83526 || (c < 92928
                ? (c < 92784
                  ? (c < 92736
                    ? (c >= 92160 && c <= 92728)
                    : c <= 92766)
                  : (c <= 92862 || (c >= 92880 && c <= 92909)))
                : (c <= 92975 || (c < 93053
                  ? (c < 93027
                    ? (c >= 92992 && c <= 92995)
                    : c <= 93047)
                  : (c <= 93071 || (c >= 93760 && c <= 93823)))))))
            : (c <= 94026 || (c < 110589
              ? (c < 94208
                ? (c < 94176
                  ? (c < 94099
                    ? c == 94032
                    : c <= 94111)
                  : (c <= 94177 || c == 94179))
                : (c <= 100343 || (c < 110576
                  ? (c < 101632
                    ? (c >= 100352 && c <= 101589)
                    : c <= 101640)
                  : (c <= 110579 || (c >= 110581 && c <= 110587)))))
              : (c <= 110590 || (c < 113664
                ? (c < 110948
                  ? (c < 110928
                    ? (c >= 110592 && c <= 110882)
                    : c <= 110930)
                  : (c <= 110951 || (c >= 110960 && c <= 111355)))
                : (c <= 113770 || (c < 113808
                  ? (c < 113792
                    ? (c >= 113776 && c <= 113788)
                    : c <= 113800)
                  : (c <= 113817 || (c >= 119808 && c <= 119892)))))))))))
        : (c <= 119964 || (c < 125259
          ? (c < 120572
            ? (c < 120086
              ? (c < 119995
                ? (c < 119973
                  ? (c < 119970
                    ? (c >= 119966 && c <= 119967)
                    : c <= 119970)
                  : (c <= 119974 || (c < 119982
                    ? (c >= 119977 && c <= 119980)
                    : c <= 119993)))
                : (c <= 119995 || (c < 120071
                  ? (c < 120005
                    ? (c >= 119997 && c <= 120003)
                    : c <= 120069)
                  : (c <= 120074 || (c >= 120077 && c <= 120084)))))
              : (c <= 120092 || (c < 120138
                ? (c < 120128
                  ? (c < 120123
                    ? (c >= 120094 && c <= 120121)
                    : c <= 120126)
                  : (c <= 120132 || c == 120134))
                : (c <= 120144 || (c < 120514
                  ? (c < 120488
                    ? (c >= 120146 && c <= 120485)
                    : c <= 120512)
                  : (c <= 120538 || (c >= 120540 && c <= 120570)))))))
            : (c <= 120596 || (c < 123191
              ? (c < 120714
                ? (c < 120656
                  ? (c < 120630
                    ? (c >= 120598 && c <= 120628)
                    : c <= 120654)
                  : (c <= 120686 || (c >= 120688 && c <= 120712)))
                : (c <= 120744 || (c < 122624
                  ? (c < 120772
                    ? (c >= 120746 && c <= 120770)
                    : c <= 120779)
                  : (c <= 122654 || (c >= 123136 && c <= 123180)))))
              : (c <= 123197 || (c < 124904
                ? (c < 123584
                  ? (c < 123536
                    ? c == 123214
                    : c <= 123565)
                  : (c <= 123627 || (c >= 124896 && c <= 124902)))
                : (c <= 124907 || (c < 124928
                  ? (c < 124912
                    ? (c >= 124909 && c <= 124910)
                    : c <= 124926)
                  : (c <= 125124 || (c >= 125184 && c <= 125251)))))))))
          : (c <= 125259 || (c < 126559
            ? (c < 126535
              ? (c < 126505
                ? (c < 126497
                  ? (c < 126469
                    ? (c >= 126464 && c <= 126467)
                    : c <= 126495)
                  : (c <= 126498 || (c < 126503
                    ? c == 126500
                    : c <= 126503)))
                : (c <= 126514 || (c < 126523
                  ? (c < 126521
                    ? (c >= 126516 && c <= 126519)
                    : c <= 126521)
                  : (c <= 126523 || c == 126530))))
              : (c <= 126535 || (c < 126548
                ? (c < 126541
                  ? (c < 126539
                    ? c == 126537
                    : c <= 126539)
                  : (c <= 126543 || (c >= 126545 && c <= 126546)))
                : (c <= 126548 || (c < 126555
                  ? (c < 126553
                    ? c == 126551
                    : c <= 126553)
                  : (c <= 126555 || c == 126557))))))
            : (c <= 126559 || (c < 126625
              ? (c < 126580
                ? (c < 126567
                  ? (c < 126564
                    ? (c >= 126561 && c <= 126562)
                    : c <= 126564)
                  : (c <= 126570 || (c >= 126572 && c <= 126578)))
                : (c <= 126583 || (c < 126592
                  ? (c < 126590
                    ? (c >= 126585 && c <= 126588)
                    : c <= 126590)
                  : (c <= 126601 || (c >= 126603 && c <= 126619)))))
              : (c <= 126627 || (c < 177984
                ? (c < 131072
                  ? (c < 126635
                    ? (c >= 126629 && c <= 126633)
                    : c <= 126651)
                  : (c <= 173791 || (c >= 173824 && c <= 177976)))
                : (c <= 178205 || (c < 194560
                  ? (c < 183984
                    ? (c >= 178208 && c <= 183969)
                    : c <= 191456)
                  : (c <= 195101 || (c >= 196608 && c <= 201546)))))))))))))))));
}

static inline bool sym_identifier_character_set_2(int32_t c) {
  return (c < 43514
    ? (c < 4193
      ? (c < 2707
        ? (c < 1994
          ? (c < 910
            ? (c < 736
              ? (c < 186
                ? (c < 'b'
                  ? (c < '_'
                    ? (c >= 'A' && c <= 'Z')
                    : c <= '_')
                  : (c <= 'z' || (c < 181
                    ? c == 170
                    : c <= 181)))
                : (c <= 186 || (c < 248
                  ? (c < 216
                    ? (c >= 192 && c <= 214)
                    : c <= 246)
                  : (c <= 705 || (c >= 710 && c <= 721)))))
              : (c <= 740 || (c < 891
                ? (c < 880
                  ? (c < 750
                    ? c == 748
                    : c <= 750)
                  : (c <= 884 || (c >= 886 && c <= 887)))
                : (c <= 893 || (c < 904
                  ? (c < 902
                    ? c == 895
                    : c <= 902)
                  : (c <= 906 || c == 908))))))
            : (c <= 929 || (c < 1649
              ? (c < 1376
                ? (c < 1162
                  ? (c < 1015
                    ? (c >= 931 && c <= 1013)
                    : c <= 1153)
                  : (c <= 1327 || (c < 1369
                    ? (c >= 1329 && c <= 1366)
                    : c <= 1369)))
                : (c <= 1416 || (c < 1568
                  ? (c < 1519
                    ? (c >= 1488 && c <= 1514)
                    : c <= 1522)
                  : (c <= 1610 || (c >= 1646 && c <= 1647)))))
              : (c <= 1747 || (c < 1791
                ? (c < 1774
                  ? (c < 1765
                    ? c == 1749
                    : c <= 1766)
                  : (c <= 1775 || (c >= 1786 && c <= 1788)))
                : (c <= 1791 || (c < 1869
                  ? (c < 1810
                    ? c == 1808
                    : c <= 1839)
                  : (c <= 1957 || c == 1969))))))))
          : (c <= 2026 || (c < 2482
            ? (c < 2208
              ? (c < 2088
                ? (c < 2048
                  ? (c < 2042
                    ? (c >= 2036 && c <= 2037)
                    : c <= 2042)
                  : (c <= 2069 || (c < 2084
                    ? c == 2074
                    : c <= 2084)))
                : (c <= 2088 || (c < 2160
                  ? (c < 2144
                    ? (c >= 2112 && c <= 2136)
                    : c <= 2154)
                  : (c <= 2183 || (c >= 2185 && c <= 2190)))))
              : (c <= 2249 || (c < 2417
                ? (c < 2384
                  ? (c < 2365
                    ? (c >= 2308 && c <= 2361)
                    : c <= 2365)
                  : (c <= 2384 || (c >= 2392 && c <= 2401)))
                : (c <= 2432 || (c < 2451
                  ? (c < 2447
                    ? (c >= 2437 && c <= 2444)
                    : c <= 2448)
                  : (c <= 2472 || (c >= 2474 && c <= 2480)))))))
            : (c <= 2482 || (c < 2579
              ? (c < 2527
                ? (c < 2510
                  ? (c < 2493
                    ? (c >= 2486 && c <= 2489)
                    : c <= 2493)
                  : (c <= 2510 || (c >= 2524 && c <= 2525)))
                : (c <= 2529 || (c < 2565
                  ? (c < 2556
                    ? (c >= 2544 && c <= 2545)
                    : c <= 2556)
                  : (c <= 2570 || (c >= 2575 && c <= 2576)))))
              : (c <= 2600 || (c < 2649
                ? (c < 2613
                  ? (c < 2610
                    ? (c >= 2602 && c <= 2608)
                    : c <= 2611)
                  : (c <= 2614 || (c >= 2616 && c <= 2617)))
                : (c <= 2652 || (c < 2693
                  ? (c < 2674
                    ? c == 2654
                    : c <= 2676)
                  : (c <= 2701 || (c >= 2703 && c <= 2705)))))))))))
        : (c <= 2728 || (c < 3242
          ? (c < 2962
            ? (c < 2858
              ? (c < 2784
                ? (c < 2741
                  ? (c < 2738
                    ? (c >= 2730 && c <= 2736)
                    : c <= 2739)
                  : (c <= 2745 || (c < 2768
                    ? c == 2749
                    : c <= 2768)))
                : (c <= 2785 || (c < 2831
                  ? (c < 2821
                    ? c == 2809
                    : c <= 2828)
                  : (c <= 2832 || (c >= 2835 && c <= 2856)))))
              : (c <= 2864 || (c < 2911
                ? (c < 2877
                  ? (c < 2869
                    ? (c >= 2866 && c <= 2867)
                    : c <= 2873)
                  : (c <= 2877 || (c >= 2908 && c <= 2909)))
                : (c <= 2913 || (c < 2949
                  ? (c < 2947
                    ? c == 2929
                    : c <= 2947)
                  : (c <= 2954 || (c >= 2958 && c <= 2960)))))))
            : (c <= 2965 || (c < 3090
              ? (c < 2984
                ? (c < 2974
                  ? (c < 2972
                    ? (c >= 2969 && c <= 2970)
                    : c <= 2972)
                  : (c <= 2975 || (c >= 2979 && c <= 2980)))
                : (c <= 2986 || (c < 3077
                  ? (c < 3024
                    ? (c >= 2990 && c <= 3001)
                    : c <= 3024)
                  : (c <= 3084 || (c >= 3086 && c <= 3088)))))
              : (c <= 3112 || (c < 3168
                ? (c < 3160
                  ? (c < 3133
                    ? (c >= 3114 && c <= 3129)
                    : c <= 3133)
                  : (c <= 3162 || c == 3165))
                : (c <= 3169 || (c < 3214
                  ? (c < 3205
                    ? c == 3200
                    : c <= 3212)
                  : (c <= 3216 || (c >= 3218 && c <= 3240)))))))))
          : (c <= 3251 || (c < 3648
            ? (c < 3412
              ? (c < 3332
                ? (c < 3293
                  ? (c < 3261
                    ? (c >= 3253 && c <= 3257)
                    : c <= 3261)
                  : (c <= 3294 || (c < 3313
                    ? (c >= 3296 && c <= 3297)
                    : c <= 3314)))
                : (c <= 3340 || (c < 3389
                  ? (c < 3346
                    ? (c >= 3342 && c <= 3344)
                    : c <= 3386)
                  : (c <= 3389 || c == 3406))))
              : (c <= 3414 || (c < 3507
                ? (c < 3461
                  ? (c < 3450
                    ? (c >= 3423 && c <= 3425)
                    : c <= 3455)
                  : (c <= 3478 || (c >= 3482 && c <= 3505)))
                : (c <= 3515 || (c < 3585
                  ? (c < 3520
                    ? c == 3517
                    : c <= 3526)
                  : (c <= 3632 || c == 3634))))))
            : (c <= 3654 || (c < 3782
              ? (c < 3749
                ? (c < 3718
                  ? (c < 3716
                    ? (c >= 3713 && c <= 3714)
                    : c <= 3716)
                  : (c <= 3722 || (c >= 3724 && c <= 3747)))
                : (c <= 3749 || (c < 3773
                  ? (c < 3762
                    ? (c >= 3751 && c <= 3760)
                    : c <= 3762)
                  : (c <= 3773 || (c >= 3776 && c <= 3780)))))
              : (c <= 3782 || (c < 3976
                ? (c < 3904
                  ? (c < 3840
                    ? (c >= 3804 && c <= 3807)
                    : c <= 3840)
                  : (c <= 3911 || (c >= 3913 && c <= 3948)))
                : (c <= 3980 || (c < 4176
                  ? (c < 4159
                    ? (c >= 4096 && c <= 4138)
                    : c <= 4159)
                  : (c <= 4181 || (c >= 4186 && c <= 4189)))))))))))))
      : (c <= 4193 || (c < 8134
        ? (c < 6176
          ? (c < 4808
            ? (c < 4688
              ? (c < 4295
                ? (c < 4213
                  ? (c < 4206
                    ? (c >= 4197 && c <= 4198)
                    : c <= 4208)
                  : (c <= 4225 || (c < 4256
                    ? c == 4238
                    : c <= 4293)))
                : (c <= 4295 || (c < 4348
                  ? (c < 4304
                    ? c == 4301
                    : c <= 4346)
                  : (c <= 4680 || (c >= 4682 && c <= 4685)))))
              : (c <= 4694 || (c < 4752
                ? (c < 4704
                  ? (c < 4698
                    ? c == 4696
                    : c <= 4701)
                  : (c <= 4744 || (c >= 4746 && c <= 4749)))
                : (c <= 4784 || (c < 4800
                  ? (c < 4792
                    ? (c >= 4786 && c <= 4789)
                    : c <= 4798)
                  : (c <= 4800 || (c >= 4802 && c <= 4805)))))))
            : (c <= 4822 || (c < 5792
              ? (c < 5024
                ? (c < 4888
                  ? (c < 4882
                    ? (c >= 4824 && c <= 4880)
                    : c <= 4885)
                  : (c <= 4954 || (c >= 4992 && c <= 5007)))
                : (c <= 5109 || (c < 5743
                  ? (c < 5121
                    ? (c >= 5112 && c <= 5117)
                    : c <= 5740)
                  : (c <= 5759 || (c >= 5761 && c <= 5786)))))
              : (c <= 5866 || (c < 5984
                ? (c < 5919
                  ? (c < 5888
                    ? (c >= 5870 && c <= 5880)
                    : c <= 5905)
                  : (c <= 5937 || (c >= 5952 && c <= 5969)))
                : (c <= 5996 || (c < 6103
                  ? (c < 6016
                    ? (c >= 5998 && c <= 6000)
                    : c <= 6067)
                  : (c <= 6103 || c == 6108))))))))
          : (c <= 6264 || (c < 7312
            ? (c < 6823
              ? (c < 6512
                ? (c < 6320
                  ? (c < 6314
                    ? (c >= 6272 && c <= 6312)
                    : c <= 6314)
                  : (c <= 6389 || (c < 6480
                    ? (c >= 6400 && c <= 6430)
                    : c <= 6509)))
                : (c <= 6516 || (c < 6656
                  ? (c < 6576
                    ? (c >= 6528 && c <= 6571)
                    : c <= 6601)
                  : (c <= 6678 || (c >= 6688 && c <= 6740)))))
              : (c <= 6823 || (c < 7098
                ? (c < 7043
                  ? (c < 6981
                    ? (c >= 6917 && c <= 6963)
                    : c <= 6988)
                  : (c <= 7072 || (c >= 7086 && c <= 7087)))
                : (c <= 7141 || (c < 7258
                  ? (c < 7245
                    ? (c >= 7168 && c <= 7203)
                    : c <= 7247)
                  : (c <= 7293 || (c >= 7296 && c <= 7304)))))))
            : (c <= 7354 || (c < 8008
              ? (c < 7418
                ? (c < 7406
                  ? (c < 7401
                    ? (c >= 7357 && c <= 7359)
                    : c <= 7404)
                  : (c <= 7411 || (c >= 7413 && c <= 7414)))
                : (c <= 7418 || (c < 7960
                  ? (c < 7680
                    ? (c >= 7424 && c <= 7615)
                    : c <= 7957)
                  : (c <= 7965 || (c >= 7968 && c <= 8005)))))
              : (c <= 8013 || (c < 8031
                ? (c < 8027
                  ? (c < 8025
                    ? (c >= 8016 && c <= 8023)
                    : c <= 8025)
                  : (c <= 8027 || c == 8029))
                : (c <= 8061 || (c < 8126
                  ? (c < 8118
                    ? (c >= 8064 && c <= 8116)
                    : c <= 8124)
                  : (c <= 8126 || (c >= 8130 && c <= 8132)))))))))))
        : (c <= 8140 || (c < 12337
          ? (c < 8544
            ? (c < 8458
              ? (c < 8305
                ? (c < 8160
                  ? (c < 8150
                    ? (c >= 8144 && c <= 8147)
                    : c <= 8155)
                  : (c <= 8172 || (c < 8182
                    ? (c >= 8178 && c <= 8180)
                    : c <= 8188)))
                : (c <= 8305 || (c < 8450
                  ? (c < 8336
                    ? c == 8319
                    : c <= 8348)
                  : (c <= 8450 || c == 8455))))
              : (c <= 8467 || (c < 8488
                ? (c < 8484
                  ? (c < 8472
                    ? c == 8469
                    : c <= 8477)
                  : (c <= 8484 || c == 8486))
                : (c <= 8488 || (c < 8517
                  ? (c < 8508
                    ? (c >= 8490 && c <= 8505)
                    : c <= 8511)
                  : (c <= 8521 || c == 8526))))))
            : (c <= 8584 || (c < 11680
              ? (c < 11559
                ? (c < 11506
                  ? (c < 11499
                    ? (c >= 11264 && c <= 11492)
                    : c <= 11502)
                  : (c <= 11507 || (c >= 11520 && c <= 11557)))
                : (c <= 11559 || (c < 11631
                  ? (c < 11568
                    ? c == 11565
                    : c <= 11623)
                  : (c <= 11631 || (c >= 11648 && c <= 11670)))))
              : (c <= 11686 || (c < 11720
                ? (c < 11704
                  ? (c < 11696
                    ? (c >= 11688 && c <= 11694)
                    : c <= 11702)
                  : (c <= 11710 || (c >= 11712 && c <= 11718)))
                : (c <= 11726 || (c < 12293
                  ? (c < 11736
                    ? (c >= 11728 && c <= 11734)
                    : c <= 11742)
                  : (c <= 12295 || (c >= 12321 && c <= 12329)))))))))
          : (c <= 12341 || (c < 42891
            ? (c < 19968
              ? (c < 12549
                ? (c < 12445
                  ? (c < 12353
                    ? (c >= 12344 && c <= 12348)
                    : c <= 12438)
                  : (c <= 12447 || (c < 12540
                    ? (c >= 12449 && c <= 12538)
                    : c <= 12543)))
                : (c <= 12591 || (c < 12784
                  ? (c < 12704
                    ? (c >= 12593 && c <= 12686)
                    : c <= 12735)
                  : (c <= 12799 || (c >= 13312 && c <= 19903)))))
              : (c <= 42124 || (c < 42560
                ? (c < 42512
                  ? (c < 42240
                    ? (c >= 42192 && c <= 42237)
                    : c <= 42508)
                  : (c <= 42527 || (c >= 42538 && c <= 42539)))
                : (c <= 42606 || (c < 42775
                  ? (c < 42656
                    ? (c >= 42623 && c <= 42653)
                    : c <= 42735)
                  : (c <= 42783 || (c >= 42786 && c <= 42888)))))))
            : (c <= 42954 || (c < 43250
              ? (c < 43011
                ? (c < 42965
                  ? (c < 42963
                    ? (c >= 42960 && c <= 42961)
                    : c <= 42963)
                  : (c <= 42969 || (c >= 42994 && c <= 43009)))
                : (c <= 43013 || (c < 43072
                  ? (c < 43020
                    ? (c >= 43015 && c <= 43018)
                    : c <= 43042)
                  : (c <= 43123 || (c >= 43138 && c <= 43187)))))
              : (c <= 43255 || (c < 43360
                ? (c < 43274
                  ? (c < 43261
                    ? c == 43259
                    : c <= 43262)
                  : (c <= 43301 || (c >= 43312 && c <= 43334)))
                : (c <= 43388 || (c < 43488
                  ? (c < 43471
                    ? (c >= 43396 && c <= 43442)
                    : c <= 43471)
                  : (c <= 43492 || (c >= 43494 && c <= 43503)))))))))))))))
    : (c <= 43518 || (c < 70727
      ? (c < 66956
        ? (c < 64914
          ? (c < 43868
            ? (c < 43714
              ? (c < 43646
                ? (c < 43588
                  ? (c < 43584
                    ? (c >= 43520 && c <= 43560)
                    : c <= 43586)
                  : (c <= 43595 || (c < 43642
                    ? (c >= 43616 && c <= 43638)
                    : c <= 43642)))
                : (c <= 43695 || (c < 43705
                  ? (c < 43701
                    ? c == 43697
                    : c <= 43702)
                  : (c <= 43709 || c == 43712))))
              : (c <= 43714 || (c < 43785
                ? (c < 43762
                  ? (c < 43744
                    ? (c >= 43739 && c <= 43741)
                    : c <= 43754)
                  : (c <= 43764 || (c >= 43777 && c <= 43782)))
                : (c <= 43790 || (c < 43816
                  ? (c < 43808
                    ? (c >= 43793 && c <= 43798)
                    : c <= 43814)
                  : (c <= 43822 || (c >= 43824 && c <= 43866)))))))
            : (c <= 43881 || (c < 64287
              ? (c < 63744
                ? (c < 55216
                  ? (c < 44032
                    ? (c >= 43888 && c <= 44002)
                    : c <= 55203)
                  : (c <= 55238 || (c >= 55243 && c <= 55291)))
                : (c <= 64109 || (c < 64275
                  ? (c < 64256
                    ? (c >= 64112 && c <= 64217)
                    : c <= 64262)
                  : (c <= 64279 || c == 64285))))
              : (c <= 64296 || (c < 64323
                ? (c < 64318
                  ? (c < 64312
                    ? (c >= 64298 && c <= 64310)
                    : c <= 64316)
                  : (c <= 64318 || (c >= 64320 && c <= 64321)))
                : (c <= 64324 || (c < 64612
                  ? (c < 64467
                    ? (c >= 64326 && c <= 64433)
                    : c <= 64605)
                  : (c <= 64829 || (c >= 64848 && c <= 64911)))))))))
          : (c <= 64967 || (c < 65599
            ? (c < 65382
              ? (c < 65147
                ? (c < 65139
                  ? (c < 65137
                    ? (c >= 65008 && c <= 65017)
                    : c <= 65137)
                  : (c <= 65139 || (c < 65145
                    ? c == 65143
                    : c <= 65145)))
                : (c <= 65147 || (c < 65313
                  ? (c < 65151
                    ? c == 65149
                    : c <= 65276)
                  : (c <= 65338 || (c >= 65345 && c <= 65370)))))
              : (c <= 65437 || (c < 65498
                ? (c < 65482
                  ? (c < 65474
                    ? (c >= 65440 && c <= 65470)
                    : c <= 65479)
                  : (c <= 65487 || (c >= 65490 && c <= 65495)))
                : (c <= 65500 || (c < 65576
                  ? (c < 65549
                    ? (c >= 65536 && c <= 65547)
                    : c <= 65574)
                  : (c <= 65594 || (c >= 65596 && c <= 65597)))))))
            : (c <= 65613 || (c < 66464
              ? (c < 66208
                ? (c < 65856
                  ? (c < 65664
                    ? (c >= 65616 && c <= 65629)
                    : c <= 65786)
                  : (c <= 65908 || (c >= 66176 && c <= 66204)))
                : (c <= 66256 || (c < 66384
                  ? (c < 66349
                    ? (c >= 66304 && c <= 66335)
                    : c <= 66378)
                  : (c <= 66421 || (c >= 66432 && c <= 66461)))))
              : (c <= 66499 || (c < 66776
                ? (c < 66560
                  ? (c < 66513
                    ? (c >= 66504 && c <= 66511)
                    : c <= 66517)
                  : (c <= 66717 || (c >= 66736 && c <= 66771)))
                : (c <= 66811 || (c < 66928
                  ? (c < 66864
                    ? (c >= 66816 && c <= 66855)
                    : c <= 66915)
                  : (c <= 66938 || (c >= 66940 && c <= 66954)))))))))))
        : (c <= 66962 || (c < 68864
          ? (c < 67828
            ? (c < 67506
              ? (c < 67072
                ? (c < 66979
                  ? (c < 66967
                    ? (c >= 66964 && c <= 66965)
                    : c <= 66977)
                  : (c <= 66993 || (c < 67003
                    ? (c >= 66995 && c <= 67001)
                    : c <= 67004)))
                : (c <= 67382 || (c < 67456
                  ? (c < 67424
                    ? (c >= 67392 && c <= 67413)
                    : c <= 67431)
                  : (c <= 67461 || (c >= 67463 && c <= 67504)))))
              : (c <= 67514 || (c < 67644
                ? (c < 67594
                  ? (c < 67592
                    ? (c >= 67584 && c <= 67589)
                    : c <= 67592)
                  : (c <= 67637 || (c >= 67639 && c <= 67640)))
                : (c <= 67644 || (c < 67712
                  ? (c < 67680
                    ? (c >= 67647 && c <= 67669)
                    : c <= 67702)
                  : (c <= 67742 || (c >= 67808 && c <= 67826)))))))
            : (c <= 67829 || (c < 68224
              ? (c < 68096
                ? (c < 67968
                  ? (c < 67872
                    ? (c >= 67840 && c <= 67861)
                    : c <= 67897)
                  : (c <= 68023 || (c >= 68030 && c <= 68031)))
                : (c <= 68096 || (c < 68121
                  ? (c < 68117
                    ? (c >= 68112 && c <= 68115)
                    : c <= 68119)
                  : (c <= 68149 || (c >= 68192 && c <= 68220)))))
              : (c <= 68252 || (c < 68448
                ? (c < 68352
                  ? (c < 68297
                    ? (c >= 68288 && c <= 68295)
                    : c <= 68324)
                  : (c <= 68405 || (c >= 68416 && c <= 68437)))
                : (c <= 68466 || (c < 68736
                  ? (c < 68608
                    ? (c >= 68480 && c <= 68497)
                    : c <= 68680)
                  : (c <= 68786 || (c >= 68800 && c <= 68850)))))))))
          : (c <= 68899 || (c < 70106
            ? (c < 69749
              ? (c < 69488
                ? (c < 69376
                  ? (c < 69296
                    ? (c >= 69248 && c <= 69289)
                    : c <= 69297)
                  : (c <= 69404 || (c < 69424
                    ? c == 69415
                    : c <= 69445)))
                : (c <= 69505 || (c < 69635
                  ? (c < 69600
                    ? (c >= 69552 && c <= 69572)
                    : c <= 69622)
                  : (c <= 69687 || (c >= 69745 && c <= 69746)))))
              : (c <= 69749 || (c < 69959
                ? (c < 69891
                  ? (c < 69840
                    ? (c >= 69763 && c <= 69807)
                    : c <= 69864)
                  : (c <= 69926 || c == 69956))
                : (c <= 69959 || (c < 70019
                  ? (c < 70006
                    ? (c >= 69968 && c <= 70002)
                    : c <= 70006)
                  : (c <= 70066 || (c >= 70081 && c <= 70084)))))))
            : (c <= 70106 || (c < 70405
              ? (c < 70280
                ? (c < 70163
                  ? (c < 70144
                    ? c == 70108
                    : c <= 70161)
                  : (c <= 70187 || (c >= 70272 && c <= 70278)))
                : (c <= 70280 || (c < 70303
                  ? (c < 70287
                    ? (c >= 70282 && c <= 70285)
                    : c <= 70301)
                  : (c <= 70312 || (c >= 70320 && c <= 70366)))))
              : (c <= 70412 || (c < 70453
                ? (c < 70442
                  ? (c < 70419
                    ? (c >= 70415 && c <= 70416)
                    : c <= 70440)
                  : (c <= 70448 || (c >= 70450 && c <= 70451)))
                : (c <= 70457 || (c < 70493
                  ? (c < 70480
                    ? c == 70461
                    : c <= 70480)
                  : (c <= 70497 || (c >= 70656 && c <= 70708)))))))))))))
      : (c <= 70730 || (c < 119894
        ? (c < 73056
          ? (c < 72001
            ? (c < 71424
              ? (c < 71128
                ? (c < 70852
                  ? (c < 70784
                    ? (c >= 70751 && c <= 70753)
                    : c <= 70831)
                  : (c <= 70853 || (c < 71040
                    ? c == 70855
                    : c <= 71086)))
                : (c <= 71131 || (c < 71296
                  ? (c < 71236
                    ? (c >= 71168 && c <= 71215)
                    : c <= 71236)
                  : (c <= 71338 || c == 71352))))
              : (c <= 71450 || (c < 71945
                ? (c < 71840
                  ? (c < 71680
                    ? (c >= 71488 && c <= 71494)
                    : c <= 71723)
                  : (c <= 71903 || (c >= 71935 && c <= 71942)))
                : (c <= 71945 || (c < 71960
                  ? (c < 71957
                    ? (c >= 71948 && c <= 71955)
                    : c <= 71958)
                  : (c <= 71983 || c == 71999))))))
            : (c <= 72001 || (c < 72349
              ? (c < 72192
                ? (c < 72161
                  ? (c < 72106
                    ? (c >= 72096 && c <= 72103)
                    : c <= 72144)
                  : (c <= 72161 || c == 72163))
                : (c <= 72192 || (c < 72272
                  ? (c < 72250
                    ? (c >= 72203 && c <= 72242)
                    : c <= 72250)
                  : (c <= 72272 || (c >= 72284 && c <= 72329)))))
              : (c <= 72349 || (c < 72818
                ? (c < 72714
                  ? (c < 72704
                    ? (c >= 72368 && c <= 72440)
                    : c <= 72712)
                  : (c <= 72750 || c == 72768))
                : (c <= 72847 || (c < 72971
                  ? (c < 72968
                    ? (c >= 72960 && c <= 72966)
                    : c <= 72969)
                  : (c <= 73008 || c == 73030))))))))
          : (c <= 73061 || (c < 93952
            ? (c < 82944
              ? (c < 73728
                ? (c < 73112
                  ? (c < 73066
                    ? (c >= 73063 && c <= 73064)
                    : c <= 73097)
                  : (c <= 73112 || (c < 73648
                    ? (c >= 73440 && c <= 73458)
                    : c <= 73648)))
                : (c <= 74649 || (c < 77712
                  ? (c < 74880
                    ? (c >= 74752 && c <= 74862)
                    : c <= 75075)
                  : (c <= 77808 || (c >= 77824 && c <= 78894)))))
              : (c <= 83526 || (c < 92928
                ? (c < 92784
                  ? (c < 92736
                    ? (c >= 92160 && c <= 92728)
                    : c <= 92766)
                  : (c <= 92862 || (c >= 92880 && c <= 92909)))
                : (c <= 92975 || (c < 93053
                  ? (c < 93027
                    ? (c >= 92992 && c <= 92995)
                    : c <= 93047)
                  : (c <= 93071 || (c >= 93760 && c <= 93823)))))))
            : (c <= 94026 || (c < 110589
              ? (c < 94208
                ? (c < 94176
                  ? (c < 94099
                    ? c == 94032
                    : c <= 94111)
                  : (c <= 94177 || c == 94179))
                : (c <= 100343 || (c < 110576
                  ? (c < 101632
                    ? (c >= 100352 && c <= 101589)
                    : c <= 101640)
                  : (c <= 110579 || (c >= 110581 && c <= 110587)))))
              : (c <= 110590 || (c < 113664
                ? (c < 110948
                  ? (c < 110928
                    ? (c >= 110592 && c <= 110882)
                    : c <= 110930)
                  : (c <= 110951 || (c >= 110960 && c <= 111355)))
                : (c <= 113770 || (c < 113808
                  ? (c < 113792
                    ? (c >= 113776 && c <= 113788)
                    : c <= 113800)
                  : (c <= 113817 || (c >= 119808 && c <= 119892)))))))))))
        : (c <= 119964 || (c < 125259
          ? (c < 120572
            ? (c < 120086
              ? (c < 119995
                ? (c < 119973
                  ? (c < 119970
                    ? (c >= 119966 && c <= 119967)
                    : c <= 119970)
                  : (c <= 119974 || (c < 119982
                    ? (c >= 119977 && c <= 119980)
                    : c <= 119993)))
                : (c <= 119995 || (c < 120071
                  ? (c < 120005
                    ? (c >= 119997 && c <= 120003)
                    : c <= 120069)
                  : (c <= 120074 || (c >= 120077 && c <= 120084)))))
              : (c <= 120092 || (c < 120138
                ? (c < 120128
                  ? (c < 120123
                    ? (c >= 120094 && c <= 120121)
                    : c <= 120126)
                  : (c <= 120132 || c == 120134))
                : (c <= 120144 || (c < 120514
                  ? (c < 120488
                    ? (c >= 120146 && c <= 120485)
                    : c <= 120512)
                  : (c <= 120538 || (c >= 120540 && c <= 120570)))))))
            : (c <= 120596 || (c < 123191
              ? (c < 120714
                ? (c < 120656
                  ? (c < 120630
                    ? (c >= 120598 && c <= 120628)
                    : c <= 120654)
                  : (c <= 120686 || (c >= 120688 && c <= 120712)))
                : (c <= 120744 || (c < 122624
                  ? (c < 120772
                    ? (c >= 120746 && c <= 120770)
                    : c <= 120779)
                  : (c <= 122654 || (c >= 123136 && c <= 123180)))))
              : (c <= 123197 || (c < 124904
                ? (c < 123584
                  ? (c < 123536
                    ? c == 123214
                    : c <= 123565)
                  : (c <= 123627 || (c >= 124896 && c <= 124902)))
                : (c <= 124907 || (c < 124928
                  ? (c < 124912
                    ? (c >= 124909 && c <= 124910)
                    : c <= 124926)
                  : (c <= 125124 || (c >= 125184 && c <= 125251)))))))))
          : (c <= 125259 || (c < 126559
            ? (c < 126535
              ? (c < 126505
                ? (c < 126497
                  ? (c < 126469
                    ? (c >= 126464 && c <= 126467)
                    : c <= 126495)
                  : (c <= 126498 || (c < 126503
                    ? c == 126500
                    : c <= 126503)))
                : (c <= 126514 || (c < 126523
                  ? (c < 126521
                    ? (c >= 126516 && c <= 126519)
                    : c <= 126521)
                  : (c <= 126523 || c == 126530))))
              : (c <= 126535 || (c < 126548
                ? (c < 126541
                  ? (c < 126539
                    ? c == 126537
                    : c <= 126539)
                  : (c <= 126543 || (c >= 126545 && c <= 126546)))
                : (c <= 126548 || (c < 126555
                  ? (c < 126553
                    ? c == 126551
                    : c <= 126553)
                  : (c <= 126555 || c == 126557))))))
            : (c <= 126559 || (c < 126625
              ? (c < 126580
                ? (c < 126567
                  ? (c < 126564
                    ? (c >= 126561 && c <= 126562)
                    : c <= 126564)
                  : (c <= 126570 || (c >= 126572 && c <= 126578)))
                : (c <= 126583 || (c < 126592
                  ? (c < 126590
                    ? (c >= 126585 && c <= 126588)
                    : c <= 126590)
                  : (c <= 126601 || (c >= 126603 && c <= 126619)))))
              : (c <= 126627 || (c < 177984
                ? (c < 131072
                  ? (c < 126635
                    ? (c >= 126629 && c <= 126633)
                    : c <= 126651)
                  : (c <= 173791 || (c >= 173824 && c <= 177976)))
                : (c <= 178205 || (c < 194560
                  ? (c < 183984
                    ? (c >= 178208 && c <= 183969)
                    : c <= 191456)
                  : (c <= 195101 || (c >= 196608 && c <= 201546)))))))))))))))));
}

static inline bool sym_identifier_character_set_3(int32_t c) {
  return (c < 43514
    ? (c < 4193
      ? (c < 2707
        ? (c < 1994
          ? (c < 910
            ? (c < 736
              ? (c < 186
                ? (c < 'a'
                  ? (c < '_'
                    ? (c >= 'A' && c <= 'Z')
                    : c <= '_')
                  : (c <= 'z' || (c < 181
                    ? c == 170
                    : c <= 181)))
                : (c <= 186 || (c < 248
                  ? (c < 216
                    ? (c >= 192 && c <= 214)
                    : c <= 246)
                  : (c <= 705 || (c >= 710 && c <= 721)))))
              : (c <= 740 || (c < 891
                ? (c < 880
                  ? (c < 750
                    ? c == 748
                    : c <= 750)
                  : (c <= 884 || (c >= 886 && c <= 887)))
                : (c <= 893 || (c < 904
                  ? (c < 902
                    ? c == 895
                    : c <= 902)
                  : (c <= 906 || c == 908))))))
            : (c <= 929 || (c < 1649
              ? (c < 1376
                ? (c < 1162
                  ? (c < 1015
                    ? (c >= 931 && c <= 1013)
                    : c <= 1153)
                  : (c <= 1327 || (c < 1369
                    ? (c >= 1329 && c <= 1366)
                    : c <= 1369)))
                : (c <= 1416 || (c < 1568
                  ? (c < 1519
                    ? (c >= 1488 && c <= 1514)
                    : c <= 1522)
                  : (c <= 1610 || (c >= 1646 && c <= 1647)))))
              : (c <= 1747 || (c < 1791
                ? (c < 1774
                  ? (c < 1765
                    ? c == 1749
                    : c <= 1766)
                  : (c <= 1775 || (c >= 1786 && c <= 1788)))
                : (c <= 1791 || (c < 1869
                  ? (c < 1810
                    ? c == 1808
                    : c <= 1839)
                  : (c <= 1957 || c == 1969))))))))
          : (c <= 2026 || (c < 2482
            ? (c < 2208
              ? (c < 2088
                ? (c < 2048
                  ? (c < 2042
                    ? (c >= 2036 && c <= 2037)
                    : c <= 2042)
                  : (c <= 2069 || (c < 2084
                    ? c == 2074
                    : c <= 2084)))
                : (c <= 2088 || (c < 2160
                  ? (c < 2144
                    ? (c >= 2112 && c <= 2136)
                    : c <= 2154)
                  : (c <= 2183 || (c >= 2185 && c <= 2190)))))
              : (c <= 2249 || (c < 2417
                ? (c < 2384
                  ? (c < 2365
                    ? (c >= 2308 && c <= 2361)
                    : c <= 2365)
                  : (c <= 2384 || (c >= 2392 && c <= 2401)))
                : (c <= 2432 || (c < 2451
                  ? (c < 2447
                    ? (c >= 2437 && c <= 2444)
                    : c <= 2448)
                  : (c <= 2472 || (c >= 2474 && c <= 2480)))))))
            : (c <= 2482 || (c < 2579
              ? (c < 2527
                ? (c < 2510
                  ? (c < 2493
                    ? (c >= 2486 && c <= 2489)
                    : c <= 2493)
                  : (c <= 2510 || (c >= 2524 && c <= 2525)))
                : (c <= 2529 || (c < 2565
                  ? (c < 2556
                    ? (c >= 2544 && c <= 2545)
                    : c <= 2556)
                  : (c <= 2570 || (c >= 2575 && c <= 2576)))))
              : (c <= 2600 || (c < 2649
                ? (c < 2613
                  ? (c < 2610
                    ? (c >= 2602 && c <= 2608)
                    : c <= 2611)
                  : (c <= 2614 || (c >= 2616 && c <= 2617)))
                : (c <= 2652 || (c < 2693
                  ? (c < 2674
                    ? c == 2654
                    : c <= 2676)
                  : (c <= 2701 || (c >= 2703 && c <= 2705)))))))))))
        : (c <= 2728 || (c < 3242
          ? (c < 2962
            ? (c < 2858
              ? (c < 2784
                ? (c < 2741
                  ? (c < 2738
                    ? (c >= 2730 && c <= 2736)
                    : c <= 2739)
                  : (c <= 2745 || (c < 2768
                    ? c == 2749
                    : c <= 2768)))
                : (c <= 2785 || (c < 2831
                  ? (c < 2821
                    ? c == 2809
                    : c <= 2828)
                  : (c <= 2832 || (c >= 2835 && c <= 2856)))))
              : (c <= 2864 || (c < 2911
                ? (c < 2877
                  ? (c < 2869
                    ? (c >= 2866 && c <= 2867)
                    : c <= 2873)
                  : (c <= 2877 || (c >= 2908 && c <= 2909)))
                : (c <= 2913 || (c < 2949
                  ? (c < 2947
                    ? c == 2929
                    : c <= 2947)
                  : (c <= 2954 || (c >= 2958 && c <= 2960)))))))
            : (c <= 2965 || (c < 3090
              ? (c < 2984
                ? (c < 2974
                  ? (c < 2972
                    ? (c >= 2969 && c <= 2970)
                    : c <= 2972)
                  : (c <= 2975 || (c >= 2979 && c <= 2980)))
                : (c <= 2986 || (c < 3077
                  ? (c < 3024
                    ? (c >= 2990 && c <= 3001)
                    : c <= 3024)
                  : (c <= 3084 || (c >= 3086 && c <= 3088)))))
              : (c <= 3112 || (c < 3168
                ? (c < 3160
                  ? (c < 3133
                    ? (c >= 3114 && c <= 3129)
                    : c <= 3133)
                  : (c <= 3162 || c == 3165))
                : (c <= 3169 || (c < 3214
                  ? (c < 3205
                    ? c == 3200
                    : c <= 3212)
                  : (c <= 3216 || (c >= 3218 && c <= 3240)))))))))
          : (c <= 3251 || (c < 3648
            ? (c < 3412
              ? (c < 3332
                ? (c < 3293
                  ? (c < 3261
                    ? (c >= 3253 && c <= 3257)
                    : c <= 3261)
                  : (c <= 3294 || (c < 3313
                    ? (c >= 3296 && c <= 3297)
                    : c <= 3314)))
                : (c <= 3340 || (c < 3389
                  ? (c < 3346
                    ? (c >= 3342 && c <= 3344)
                    : c <= 3386)
                  : (c <= 3389 || c == 3406))))
              : (c <= 3414 || (c < 3507
                ? (c < 3461
                  ? (c < 3450
                    ? (c >= 3423 && c <= 3425)
                    : c <= 3455)
                  : (c <= 3478 || (c >= 3482 && c <= 3505)))
                : (c <= 3515 || (c < 3585
                  ? (c < 3520
                    ? c == 3517
                    : c <= 3526)
                  : (c <= 3632 || c == 3634))))))
            : (c <= 3654 || (c < 3782
              ? (c < 3749
                ? (c < 3718
                  ? (c < 3716
                    ? (c >= 3713 && c <= 3714)
                    : c <= 3716)
                  : (c <= 3722 || (c >= 3724 && c <= 3747)))
                : (c <= 3749 || (c < 3773
                  ? (c < 3762
                    ? (c >= 3751 && c <= 3760)
                    : c <= 3762)
                  : (c <= 3773 || (c >= 3776 && c <= 3780)))))
              : (c <= 3782 || (c < 3976
                ? (c < 3904
                  ? (c < 3840
                    ? (c >= 3804 && c <= 3807)
                    : c <= 3840)
                  : (c <= 3911 || (c >= 3913 && c <= 3948)))
                : (c <= 3980 || (c < 4176
                  ? (c < 4159
                    ? (c >= 4096 && c <= 4138)
                    : c <= 4159)
                  : (c <= 4181 || (c >= 4186 && c <= 4189)))))))))))))
      : (c <= 4193 || (c < 8134
        ? (c < 6176
          ? (c < 4808
            ? (c < 4688
              ? (c < 4295
                ? (c < 4213
                  ? (c < 4206
                    ? (c >= 4197 && c <= 4198)
                    : c <= 4208)
                  : (c <= 4225 || (c < 4256
                    ? c == 4238
                    : c <= 4293)))
                : (c <= 4295 || (c < 4348
                  ? (c < 4304
                    ? c == 4301
                    : c <= 4346)
                  : (c <= 4680 || (c >= 4682 && c <= 4685)))))
              : (c <= 4694 || (c < 4752
                ? (c < 4704
                  ? (c < 4698
                    ? c == 4696
                    : c <= 4701)
                  : (c <= 4744 || (c >= 4746 && c <= 4749)))
                : (c <= 4784 || (c < 4800
                  ? (c < 4792
                    ? (c >= 4786 && c <= 4789)
                    : c <= 4798)
                  : (c <= 4800 || (c >= 4802 && c <= 4805)))))))
            : (c <= 4822 || (c < 5792
              ? (c < 5024
                ? (c < 4888
                  ? (c < 4882
                    ? (c >= 4824 && c <= 4880)
                    : c <= 4885)
                  : (c <= 4954 || (c >= 4992 && c <= 5007)))
                : (c <= 5109 || (c < 5743
                  ? (c < 5121
                    ? (c >= 5112 && c <= 5117)
                    : c <= 5740)
                  : (c <= 5759 || (c >= 5761 && c <= 5786)))))
              : (c <= 5866 || (c < 5984
                ? (c < 5919
                  ? (c < 5888
                    ? (c >= 5870 && c <= 5880)
                    : c <= 5905)
                  : (c <= 5937 || (c >= 5952 && c <= 5969)))
                : (c <= 5996 || (c < 6103
                  ? (c < 6016
                    ? (c >= 5998 && c <= 6000)
                    : c <= 6067)
                  : (c <= 6103 || c == 6108))))))))
          : (c <= 6264 || (c < 7312
            ? (c < 6823
              ? (c < 6512
                ? (c < 6320
                  ? (c < 6314
                    ? (c >= 6272 && c <= 6312)
                    : c <= 6314)
                  : (c <= 6389 || (c < 6480
                    ? (c >= 6400 && c <= 6430)
                    : c <= 6509)))
                : (c <= 6516 || (c < 6656
                  ? (c < 6576
                    ? (c >= 6528 && c <= 6571)
                    : c <= 6601)
                  : (c <= 6678 || (c >= 6688 && c <= 6740)))))
              : (c <= 6823 || (c < 7098
                ? (c < 7043
                  ? (c < 6981
                    ? (c >= 6917 && c <= 6963)
                    : c <= 6988)
                  : (c <= 7072 || (c >= 7086 && c <= 7087)))
                : (c <= 7141 || (c < 7258
                  ? (c < 7245
                    ? (c >= 7168 && c <= 7203)
                    : c <= 7247)
                  : (c <= 7293 || (c >= 7296 && c <= 7304)))))))
            : (c <= 7354 || (c < 8008
              ? (c < 7418
                ? (c < 7406
                  ? (c < 7401
                    ? (c >= 7357 && c <= 7359)
                    : c <= 7404)
                  : (c <= 7411 || (c >= 7413 && c <= 7414)))
                : (c <= 7418 || (c < 7960
                  ? (c < 7680
                    ? (c >= 7424 && c <= 7615)
                    : c <= 7957)
                  : (c <= 7965 || (c >= 7968 && c <= 8005)))))
              : (c <= 8013 || (c < 8031
                ? (c < 8027
                  ? (c < 8025
                    ? (c >= 8016 && c <= 8023)
                    : c <= 8025)
                  : (c <= 8027 || c == 8029))
                : (c <= 8061 || (c < 8126
                  ? (c < 8118
                    ? (c >= 8064 && c <= 8116)
                    : c <= 8124)
                  : (c <= 8126 || (c >= 8130 && c <= 8132)))))))))))
        : (c <= 8140 || (c < 12337
          ? (c < 8544
            ? (c < 8458
              ? (c < 8305
                ? (c < 8160
                  ? (c < 8150
                    ? (c >= 8144 && c <= 8147)
                    : c <= 8155)
                  : (c <= 8172 || (c < 8182
                    ? (c >= 8178 && c <= 8180)
                    : c <= 8188)))
                : (c <= 8305 || (c < 8450
                  ? (c < 8336
                    ? c == 8319
                    : c <= 8348)
                  : (c <= 8450 || c == 8455))))
              : (c <= 8467 || (c < 8488
                ? (c < 8484
                  ? (c < 8472
                    ? c == 8469
                    : c <= 8477)
                  : (c <= 8484 || c == 8486))
                : (c <= 8488 || (c < 8517
                  ? (c < 8508
                    ? (c >= 8490 && c <= 8505)
                    : c <= 8511)
                  : (c <= 8521 || c == 8526))))))
            : (c <= 8584 || (c < 11680
              ? (c < 11559
                ? (c < 11506
                  ? (c < 11499
                    ? (c >= 11264 && c <= 11492)
                    : c <= 11502)
                  : (c <= 11507 || (c >= 11520 && c <= 11557)))
                : (c <= 11559 || (c < 11631
                  ? (c < 11568
                    ? c == 11565
                    : c <= 11623)
                  : (c <= 11631 || (c >= 11648 && c <= 11670)))))
              : (c <= 11686 || (c < 11720
                ? (c < 11704
                  ? (c < 11696
                    ? (c >= 11688 && c <= 11694)
                    : c <= 11702)
                  : (c <= 11710 || (c >= 11712 && c <= 11718)))
                : (c <= 11726 || (c < 12293
                  ? (c < 11736
                    ? (c >= 11728 && c <= 11734)
                    : c <= 11742)
                  : (c <= 12295 || (c >= 12321 && c <= 12329)))))))))
          : (c <= 12341 || (c < 42891
            ? (c < 19968
              ? (c < 12549
                ? (c < 12445
                  ? (c < 12353
                    ? (c >= 12344 && c <= 12348)
                    : c <= 12438)
                  : (c <= 12447 || (c < 12540
                    ? (c >= 12449 && c <= 12538)
                    : c <= 12543)))
                : (c <= 12591 || (c < 12784
                  ? (c < 12704
                    ? (c >= 12593 && c <= 12686)
                    : c <= 12735)
                  : (c <= 12799 || (c >= 13312 && c <= 19903)))))
              : (c <= 42124 || (c < 42560
                ? (c < 42512
                  ? (c < 42240
                    ? (c >= 42192 && c <= 42237)
                    : c <= 42508)
                  : (c <= 42527 || (c >= 42538 && c <= 42539)))
                : (c <= 42606 || (c < 42775
                  ? (c < 42656
                    ? (c >= 42623 && c <= 42653)
                    : c <= 42735)
                  : (c <= 42783 || (c >= 42786 && c <= 42888)))))))
            : (c <= 42954 || (c < 43250
              ? (c < 43011
                ? (c < 42965
                  ? (c < 42963
                    ? (c >= 42960 && c <= 42961)
                    : c <= 42963)
                  : (c <= 42969 || (c >= 42994 && c <= 43009)))
                : (c <= 43013 || (c < 43072
                  ? (c < 43020
                    ? (c >= 43015 && c <= 43018)
                    : c <= 43042)
                  : (c <= 43123 || (c >= 43138 && c <= 43187)))))
              : (c <= 43255 || (c < 43360
                ? (c < 43274
                  ? (c < 43261
                    ? c == 43259
                    : c <= 43262)
                  : (c <= 43301 || (c >= 43312 && c <= 43334)))
                : (c <= 43388 || (c < 43488
                  ? (c < 43471
                    ? (c >= 43396 && c <= 43442)
                    : c <= 43471)
                  : (c <= 43492 || (c >= 43494 && c <= 43503)))))))))))))))
    : (c <= 43518 || (c < 70727
      ? (c < 66956
        ? (c < 64914
          ? (c < 43868
            ? (c < 43714
              ? (c < 43646
                ? (c < 43588
                  ? (c < 43584
                    ? (c >= 43520 && c <= 43560)
                    : c <= 43586)
                  : (c <= 43595 || (c < 43642
                    ? (c >= 43616 && c <= 43638)
                    : c <= 43642)))
                : (c <= 43695 || (c < 43705
                  ? (c < 43701
                    ? c == 43697
                    : c <= 43702)
                  : (c <= 43709 || c == 43712))))
              : (c <= 43714 || (c < 43785
                ? (c < 43762
                  ? (c < 43744
                    ? (c >= 43739 && c <= 43741)
                    : c <= 43754)
                  : (c <= 43764 || (c >= 43777 && c <= 43782)))
                : (c <= 43790 || (c < 43816
                  ? (c < 43808
                    ? (c >= 43793 && c <= 43798)
                    : c <= 43814)
                  : (c <= 43822 || (c >= 43824 && c <= 43866)))))))
            : (c <= 43881 || (c < 64287
              ? (c < 63744
                ? (c < 55216
                  ? (c < 44032
                    ? (c >= 43888 && c <= 44002)
                    : c <= 55203)
                  : (c <= 55238 || (c >= 55243 && c <= 55291)))
                : (c <= 64109 || (c < 64275
                  ? (c < 64256
                    ? (c >= 64112 && c <= 64217)
                    : c <= 64262)
                  : (c <= 64279 || c == 64285))))
              : (c <= 64296 || (c < 64323
                ? (c < 64318
                  ? (c < 64312
                    ? (c >= 64298 && c <= 64310)
                    : c <= 64316)
                  : (c <= 64318 || (c >= 64320 && c <= 64321)))
                : (c <= 64324 || (c < 64612
                  ? (c < 64467
                    ? (c >= 64326 && c <= 64433)
                    : c <= 64605)
                  : (c <= 64829 || (c >= 64848 && c <= 64911)))))))))
          : (c <= 64967 || (c < 65599
            ? (c < 65382
              ? (c < 65147
                ? (c < 65139
                  ? (c < 65137
                    ? (c >= 65008 && c <= 65017)
                    : c <= 65137)
                  : (c <= 65139 || (c < 65145
                    ? c == 65143
                    : c <= 65145)))
                : (c <= 65147 || (c < 65313
                  ? (c < 65151
                    ? c == 65149
                    : c <= 65276)
                  : (c <= 65338 || (c >= 65345 && c <= 65370)))))
              : (c <= 65437 || (c < 65498
                ? (c < 65482
                  ? (c < 65474
                    ? (c >= 65440 && c <= 65470)
                    : c <= 65479)
                  : (c <= 65487 || (c >= 65490 && c <= 65495)))
                : (c <= 65500 || (c < 65576
                  ? (c < 65549
                    ? (c >= 65536 && c <= 65547)
                    : c <= 65574)
                  : (c <= 65594 || (c >= 65596 && c <= 65597)))))))
            : (c <= 65613 || (c < 66464
              ? (c < 66208
                ? (c < 65856
                  ? (c < 65664
                    ? (c >= 65616 && c <= 65629)
                    : c <= 65786)
                  : (c <= 65908 || (c >= 66176 && c <= 66204)))
                : (c <= 66256 || (c < 66384
                  ? (c < 66349
                    ? (c >= 66304 && c <= 66335)
                    : c <= 66378)
                  : (c <= 66421 || (c >= 66432 && c <= 66461)))))
              : (c <= 66499 || (c < 66776
                ? (c < 66560
                  ? (c < 66513
                    ? (c >= 66504 && c <= 66511)
                    : c <= 66517)
                  : (c <= 66717 || (c >= 66736 && c <= 66771)))
                : (c <= 66811 || (c < 66928
                  ? (c < 66864
                    ? (c >= 66816 && c <= 66855)
                    : c <= 66915)
                  : (c <= 66938 || (c >= 66940 && c <= 66954)))))))))))
        : (c <= 66962 || (c < 68864
          ? (c < 67828
            ? (c < 67506
              ? (c < 67072
                ? (c < 66979
                  ? (c < 66967
                    ? (c >= 66964 && c <= 66965)
                    : c <= 66977)
                  : (c <= 66993 || (c < 67003
                    ? (c >= 66995 && c <= 67001)
                    : c <= 67004)))
                : (c <= 67382 || (c < 67456
                  ? (c < 67424
                    ? (c >= 67392 && c <= 67413)
                    : c <= 67431)
                  : (c <= 67461 || (c >= 67463 && c <= 67504)))))
              : (c <= 67514 || (c < 67644
                ? (c < 67594
                  ? (c < 67592
                    ? (c >= 67584 && c <= 67589)
                    : c <= 67592)
                  : (c <= 67637 || (c >= 67639 && c <= 67640)))
                : (c <= 67644 || (c < 67712
                  ? (c < 67680
                    ? (c >= 67647 && c <= 67669)
                    : c <= 67702)
                  : (c <= 67742 || (c >= 67808 && c <= 67826)))))))
            : (c <= 67829 || (c < 68224
              ? (c < 68096
                ? (c < 67968
                  ? (c < 67872
                    ? (c >= 67840 && c <= 67861)
                    : c <= 67897)
                  : (c <= 68023 || (c >= 68030 && c <= 68031)))
                : (c <= 68096 || (c < 68121
                  ? (c < 68117
                    ? (c >= 68112 && c <= 68115)
                    : c <= 68119)
                  : (c <= 68149 || (c >= 68192 && c <= 68220)))))
              : (c <= 68252 || (c < 68448
                ? (c < 68352
                  ? (c < 68297
                    ? (c >= 68288 && c <= 68295)
                    : c <= 68324)
                  : (c <= 68405 || (c >= 68416 && c <= 68437)))
                : (c <= 68466 || (c < 68736
                  ? (c < 68608
                    ? (c >= 68480 && c <= 68497)
                    : c <= 68680)
                  : (c <= 68786 || (c >= 68800 && c <= 68850)))))))))
          : (c <= 68899 || (c < 70106
            ? (c < 69749
              ? (c < 69488
                ? (c < 69376
                  ? (c < 69296
                    ? (c >= 69248 && c <= 69289)
                    : c <= 69297)
                  : (c <= 69404 || (c < 69424
                    ? c == 69415
                    : c <= 69445)))
                : (c <= 69505 || (c < 69635
                  ? (c < 69600
                    ? (c >= 69552 && c <= 69572)
                    : c <= 69622)
                  : (c <= 69687 || (c >= 69745 && c <= 69746)))))
              : (c <= 69749 || (c < 69959
                ? (c < 69891
                  ? (c < 69840
                    ? (c >= 69763 && c <= 69807)
                    : c <= 69864)
                  : (c <= 69926 || c == 69956))
                : (c <= 69959 || (c < 70019
                  ? (c < 70006
                    ? (c >= 69968 && c <= 70002)
                    : c <= 70006)
                  : (c <= 70066 || (c >= 70081 && c <= 70084)))))))
            : (c <= 70106 || (c < 70405
              ? (c < 70280
                ? (c < 70163
                  ? (c < 70144
                    ? c == 70108
                    : c <= 70161)
                  : (c <= 70187 || (c >= 70272 && c <= 70278)))
                : (c <= 70280 || (c < 70303
                  ? (c < 70287
                    ? (c >= 70282 && c <= 70285)
                    : c <= 70301)
                  : (c <= 70312 || (c >= 70320 && c <= 70366)))))
              : (c <= 70412 || (c < 70453
                ? (c < 70442
                  ? (c < 70419
                    ? (c >= 70415 && c <= 70416)
                    : c <= 70440)
                  : (c <= 70448 || (c >= 70450 && c <= 70451)))
                : (c <= 70457 || (c < 70493
                  ? (c < 70480
                    ? c == 70461
                    : c <= 70480)
                  : (c <= 70497 || (c >= 70656 && c <= 70708)))))))))))))
      : (c <= 70730 || (c < 119894
        ? (c < 73056
          ? (c < 72001
            ? (c < 71424
              ? (c < 71128
                ? (c < 70852
                  ? (c < 70784
                    ? (c >= 70751 && c <= 70753)
                    : c <= 70831)
                  : (c <= 70853 || (c < 71040
                    ? c == 70855
                    : c <= 71086)))
                : (c <= 71131 || (c < 71296
                  ? (c < 71236
                    ? (c >= 71168 && c <= 71215)
                    : c <= 71236)
                  : (c <= 71338 || c == 71352))))
              : (c <= 71450 || (c < 71945
                ? (c < 71840
                  ? (c < 71680
                    ? (c >= 71488 && c <= 71494)
                    : c <= 71723)
                  : (c <= 71903 || (c >= 71935 && c <= 71942)))
                : (c <= 71945 || (c < 71960
                  ? (c < 71957
                    ? (c >= 71948 && c <= 71955)
                    : c <= 71958)
                  : (c <= 71983 || c == 71999))))))
            : (c <= 72001 || (c < 72349
              ? (c < 72192
                ? (c < 72161
                  ? (c < 72106
                    ? (c >= 72096 && c <= 72103)
                    : c <= 72144)
                  : (c <= 72161 || c == 72163))
                : (c <= 72192 || (c < 72272
                  ? (c < 72250
                    ? (c >= 72203 && c <= 72242)
                    : c <= 72250)
                  : (c <= 72272 || (c >= 72284 && c <= 72329)))))
              : (c <= 72349 || (c < 72818
                ? (c < 72714
                  ? (c < 72704
                    ? (c >= 72368 && c <= 72440)
                    : c <= 72712)
                  : (c <= 72750 || c == 72768))
                : (c <= 72847 || (c < 72971
                  ? (c < 72968
                    ? (c >= 72960 && c <= 72966)
                    : c <= 72969)
                  : (c <= 73008 || c == 73030))))))))
          : (c <= 73061 || (c < 93952
            ? (c < 82944
              ? (c < 73728
                ? (c < 73112
                  ? (c < 73066
                    ? (c >= 73063 && c <= 73064)
                    : c <= 73097)
                  : (c <= 73112 || (c < 73648
                    ? (c >= 73440 && c <= 73458)
                    : c <= 73648)))
                : (c <= 74649 || (c < 77712
                  ? (c < 74880
                    ? (c >= 74752 && c <= 74862)
                    : c <= 75075)
                  : (c <= 77808 || (c >= 77824 && c <= 78894)))))
              : (c <= 83526 || (c < 92928
                ? (c < 92784
                  ? (c < 92736
                    ? (c >= 92160 && c <= 92728)
                    : c <= 92766)
                  : (c <= 92862 || (c >= 92880 && c <= 92909)))
                : (c <= 92975 || (c < 93053
                  ? (c < 93027
                    ? (c >= 92992 && c <= 92995)
                    : c <= 93047)
                  : (c <= 93071 || (c >= 93760 && c <= 93823)))))))
            : (c <= 94026 || (c < 110589
              ? (c < 94208
                ? (c < 94176
                  ? (c < 94099
                    ? c == 94032
                    : c <= 94111)
                  : (c <= 94177 || c == 94179))
                : (c <= 100343 || (c < 110576
                  ? (c < 101632
                    ? (c >= 100352 && c <= 101589)
                    : c <= 101640)
                  : (c <= 110579 || (c >= 110581 && c <= 110587)))))
              : (c <= 110590 || (c < 113664
                ? (c < 110948
                  ? (c < 110928
                    ? (c >= 110592 && c <= 110882)
                    : c <= 110930)
                  : (c <= 110951 || (c >= 110960 && c <= 111355)))
                : (c <= 113770 || (c < 113808
                  ? (c < 113792
                    ? (c >= 113776 && c <= 113788)
                    : c <= 113800)
                  : (c <= 113817 || (c >= 119808 && c <= 119892)))))))))))
        : (c <= 119964 || (c < 125259
          ? (c < 120572
            ? (c < 120086
              ? (c < 119995
                ? (c < 119973
                  ? (c < 119970
                    ? (c >= 119966 && c <= 119967)
                    : c <= 119970)
                  : (c <= 119974 || (c < 119982
                    ? (c >= 119977 && c <= 119980)
                    : c <= 119993)))
                : (c <= 119995 || (c < 120071
                  ? (c < 120005
                    ? (c >= 119997 && c <= 120003)
                    : c <= 120069)
                  : (c <= 120074 || (c >= 120077 && c <= 120084)))))
              : (c <= 120092 || (c < 120138
                ? (c < 120128
                  ? (c < 120123
                    ? (c >= 120094 && c <= 120121)
                    : c <= 120126)
                  : (c <= 120132 || c == 120134))
                : (c <= 120144 || (c < 120514
                  ? (c < 120488
                    ? (c >= 120146 && c <= 120485)
                    : c <= 120512)
                  : (c <= 120538 || (c >= 120540 && c <= 120570)))))))
            : (c <= 120596 || (c < 123191
              ? (c < 120714
                ? (c < 120656
                  ? (c < 120630
                    ? (c >= 120598 && c <= 120628)
                    : c <= 120654)
                  : (c <= 120686 || (c >= 120688 && c <= 120712)))
                : (c <= 120744 || (c < 122624
                  ? (c < 120772
                    ? (c >= 120746 && c <= 120770)
                    : c <= 120779)
                  : (c <= 122654 || (c >= 123136 && c <= 123180)))))
              : (c <= 123197 || (c < 124904
                ? (c < 123584
                  ? (c < 123536
                    ? c == 123214
                    : c <= 123565)
                  : (c <= 123627 || (c >= 124896 && c <= 124902)))
                : (c <= 124907 || (c < 124928
                  ? (c < 124912
                    ? (c >= 124909 && c <= 124910)
                    : c <= 124926)
                  : (c <= 125124 || (c >= 125184 && c <= 125251)))))))))
          : (c <= 125259 || (c < 126559
            ? (c < 126535
              ? (c < 126505
                ? (c < 126497
                  ? (c < 126469
                    ? (c >= 126464 && c <= 126467)
                    : c <= 126495)
                  : (c <= 126498 || (c < 126503
                    ? c == 126500
                    : c <= 126503)))
                : (c <= 126514 || (c < 126523
                  ? (c < 126521
                    ? (c >= 126516 && c <= 126519)
                    : c <= 126521)
                  : (c <= 126523 || c == 126530))))
              : (c <= 126535 || (c < 126548
                ? (c < 126541
                  ? (c < 126539
                    ? c == 126537
                    : c <= 126539)
                  : (c <= 126543 || (c >= 126545 && c <= 126546)))
                : (c <= 126548 || (c < 126555
                  ? (c < 126553
                    ? c == 126551
                    : c <= 126553)
                  : (c <= 126555 || c == 126557))))))
            : (c <= 126559 || (c < 126625
              ? (c < 126580
                ? (c < 126567
                  ? (c < 126564
                    ? (c >= 126561 && c <= 126562)
                    : c <= 126564)
                  : (c <= 126570 || (c >= 126572 && c <= 126578)))
                : (c <= 126583 || (c < 126592
                  ? (c < 126590
                    ? (c >= 126585 && c <= 126588)
                    : c <= 126590)
                  : (c <= 126601 || (c >= 126603 && c <= 126619)))))
              : (c <= 126627 || (c < 177984
                ? (c < 131072
                  ? (c < 126635
                    ? (c >= 126629 && c <= 126633)
                    : c <= 126651)
                  : (c <= 173791 || (c >= 173824 && c <= 177976)))
                : (c <= 178205 || (c < 194560
                  ? (c < 183984
                    ? (c >= 178208 && c <= 183969)
                    : c <= 191456)
                  : (c <= 195101 || (c >= 196608 && c <= 201546)))))))))))))))));
}

static inline bool sym_identifier_character_set_4(int32_t c) {
  return (c < 43616
    ? (c < 3782
      ? (c < 2748
        ? (c < 2045
          ? (c < 1015
            ? (c < 710
              ? (c < 181
                ? (c < '_'
                  ? (c < 'A'
                    ? (c >= '0' && c <= '9')
                    : c <= 'Z')
                  : (c <= '_' || (c < 170
                    ? (c >= 'a' && c <= 'z')
                    : c <= 170)))
                : (c <= 181 || (c < 192
                  ? (c < 186
                    ? c == 183
                    : c <= 186)
                  : (c <= 214 || (c < 248
                    ? (c >= 216 && c <= 246)
                    : c <= 705)))))
              : (c <= 721 || (c < 891
                ? (c < 750
                  ? (c < 748
                    ? (c >= 736 && c <= 740)
                    : c <= 748)
                  : (c <= 750 || (c < 886
                    ? (c >= 768 && c <= 884)
                    : c <= 887)))
                : (c <= 893 || (c < 908
                  ? (c < 902
                    ? c == 895
                    : c <= 906)
                  : (c <= 908 || (c < 931
                    ? (c >= 910 && c <= 929)
                    : c <= 1013)))))))
            : (c <= 1153 || (c < 1519
              ? (c < 1425
                ? (c < 1329
                  ? (c < 1162
                    ? (c >= 1155 && c <= 1159)
                    : c <= 1327)
                  : (c <= 1366 || (c < 1376
                    ? c == 1369
                    : c <= 1416)))
                : (c <= 1469 || (c < 1476
                  ? (c < 1473
                    ? c == 1471
                    : c <= 1474)
                  : (c <= 1477 || (c < 1488
                    ? c == 1479
                    : c <= 1514)))))
              : (c <= 1522 || (c < 1770
                ? (c < 1646
                  ? (c < 1568
                    ? (c >= 1552 && c <= 1562)
                    : c <= 1641)
                  : (c <= 1747 || (c < 1759
                    ? (c >= 1749 && c <= 1756)
                    : c <= 1768)))
                : (c <= 1788 || (c < 1869
                  ? (c < 1808
                    ? c == 1791
                    : c <= 1866)
                  : (c <= 1969 || (c < 2042
                    ? (c >= 1984 && c <= 2037)
                    : c <= 2042)))))))))
          : (c <= 2045 || (c < 2558
            ? (c < 2451
              ? (c < 2200
                ? (c < 2144
                  ? (c < 2112
                    ? (c >= 2048 && c <= 2093)
                    : c <= 2139)
                  : (c <= 2154 || (c < 2185
                    ? (c >= 2160 && c <= 2183)
                    : c <= 2190)))
                : (c <= 2273 || (c < 2417
                  ? (c < 2406
                    ? (c >= 2275 && c <= 2403)
                    : c <= 2415)
                  : (c <= 2435 || (c < 2447
                    ? (c >= 2437 && c <= 2444)
                    : c <= 2448)))))
              : (c <= 2472 || (c < 2507
                ? (c < 2486
                  ? (c < 2482
                    ? (c >= 2474 && c <= 2480)
                    : c <= 2482)
                  : (c <= 2489 || (c < 2503
                    ? (c >= 2492 && c <= 2500)
                    : c <= 2504)))
                : (c <= 2510 || (c < 2527
                  ? (c < 2524
                    ? c == 2519
                    : c <= 2525)
                  : (c <= 2531 || (c < 2556
                    ? (c >= 2534 && c <= 2545)
                    : c <= 2556)))))))
            : (c <= 2558 || (c < 2635
              ? (c < 2610
                ? (c < 2575
                  ? (c < 2565
                    ? (c >= 2561 && c <= 2563)
                    : c <= 2570)
                  : (c <= 2576 || (c < 2602
                    ? (c >= 2579 && c <= 2600)
                    : c <= 2608)))
                : (c <= 2611 || (c < 2620
                  ? (c < 2616
                    ? (c >= 2613 && c <= 2614)
                    : c <= 2617)
                  : (c <= 2620 || (c < 2631
                    ? (c >= 2622 && c <= 2626)
                    : c <= 2632)))))
              : (c <= 2637 || (c < 2693
                ? (c < 2654
                  ? (c < 2649
                    ? c == 2641
                    : c <= 2652)
                  : (c <= 2654 || (c < 2689
                    ? (c >= 2662 && c <= 2677)
                    : c <= 2691)))
                : (c <= 2701 || (c < 2730
                  ? (c < 2707
                    ? (c >= 2703 && c <= 2705)
                    : c <= 2728)
                  : (c <= 2736 || (c < 2741
                    ? (c >= 2738 && c <= 2739)
                    : c <= 2745)))))))))))
        : (c <= 2757 || (c < 3168
          ? (c < 2958
            ? (c < 2866
              ? (c < 2809
                ? (c < 2768
                  ? (c < 2763
                    ? (c >= 2759 && c <= 2761)
                    : c <= 2765)
                  : (c <= 2768 || (c < 2790
                    ? (c >= 2784 && c <= 2787)
                    : c <= 2799)))
                : (c <= 2815 || (c < 2831
                  ? (c < 2821
                    ? (c >= 2817 && c <= 2819)
                    : c <= 2828)
                  : (c <= 2832 || (c < 2858
                    ? (c >= 2835 && c <= 2856)
                    : c <= 2864)))))
              : (c <= 2867 || (c < 2908
                ? (c < 2887
                  ? (c < 2876
                    ? (c >= 2869 && c <= 2873)
                    : c <= 2884)
                  : (c <= 2888 || (c < 2901
                    ? (c >= 2891 && c <= 2893)
                    : c <= 2903)))
                : (c <= 2909 || (c < 2929
                  ? (c < 2918
                    ? (c >= 2911 && c <= 2915)
                    : c <= 2927)
                  : (c <= 2929 || (c < 2949
                    ? (c >= 2946 && c <= 2947)
                    : c <= 2954)))))))
            : (c <= 2960 || (c < 3031
              ? (c < 2984
                ? (c < 2972
                  ? (c < 2969
                    ? (c >= 2962 && c <= 2965)
                    : c <= 2970)
                  : (c <= 2972 || (c < 2979
                    ? (c >= 2974 && c <= 2975)
                    : c <= 2980)))
                : (c <= 2986 || (c < 3014
                  ? (c < 3006
                    ? (c >= 2990 && c <= 3001)
                    : c <= 3010)
                  : (c <= 3016 || (c < 3024
                    ? (c >= 3018 && c <= 3021)
                    : c <= 3024)))))
              : (c <= 3031 || (c < 3132
                ? (c < 3086
                  ? (c < 3072
                    ? (c >= 3046 && c <= 3055)
                    : c <= 3084)
                  : (c <= 3088 || (c < 3114
                    ? (c >= 3090 && c <= 3112)
                    : c <= 3129)))
                : (c <= 3140 || (c < 3157
                  ? (c < 3146
                    ? (c >= 3142 && c <= 3144)
                    : c <= 3149)
                  : (c <= 3158 || (c < 3165
                    ? (c >= 3160 && c <= 3162)
                    : c <= 3165)))))))))
          : (c <= 3171 || (c < 3450
            ? (c < 3293
              ? (c < 3242
                ? (c < 3205
                  ? (c < 3200
                    ? (c >= 3174 && c <= 3183)
                    : c <= 3203)
                  : (c <= 3212 || (c < 3218
                    ? (c >= 3214 && c <= 3216)
                    : c <= 3240)))
                : (c <= 3251 || (c < 3270
                  ? (c < 3260
                    ? (c >= 3253 && c <= 3257)
                    : c <= 3268)
                  : (c <= 3272 || (c < 3285
                    ? (c >= 3274 && c <= 3277)
                    : c <= 3286)))))
              : (c <= 3294 || (c < 3346
                ? (c < 3313
                  ? (c < 3302
                    ? (c >= 3296 && c <= 3299)
                    : c <= 3311)
                  : (c <= 3314 || (c < 3342
                    ? (c >= 3328 && c <= 3340)
                    : c <= 3344)))
                : (c <= 3396 || (c < 3412
                  ? (c < 3402
                    ? (c >= 3398 && c <= 3400)
                    : c <= 3406)
                  : (c <= 3415 || (c < 3430
                    ? (c >= 3423 && c <= 3427)
                    : c <= 3439)))))))
            : (c <= 3455 || (c < 3570
              ? (c < 3520
                ? (c < 3482
                  ? (c < 3461
                    ? (c >= 3457 && c <= 3459)
                    : c <= 3478)
                  : (c <= 3505 || (c < 3517
                    ? (c >= 3507 && c <= 3515)
                    : c <= 3517)))
                : (c <= 3526 || (c < 3542
                  ? (c < 3535
                    ? c == 3530
                    : c <= 3540)
                  : (c <= 3542 || (c < 3558
                    ? (c >= 3544 && c <= 3551)
                    : c <= 3567)))))
              : (c <= 3571 || (c < 3718
                ? (c < 3664
                  ? (c < 3648
                    ? (c >= 3585 && c <= 3642)
                    : c <= 3662)
                  : (c <= 3673 || (c < 3716
                    ? (c >= 3713 && c <= 3714)
                    : c <= 3716)))
                : (c <= 3722 || (c < 3751
                  ? (c < 3749
                    ? (c >= 3724 && c <= 3747)
                    : c <= 3749)
                  : (c <= 3773 || (c >= 3776 && c <= 3780)))))))))))))
      : (c <= 3782 || (c < 8025
        ? (c < 5888
          ? (c < 4688
            ? (c < 3953
              ? (c < 3872
                ? (c < 3804
                  ? (c < 3792
                    ? (c >= 3784 && c <= 3789)
                    : c <= 3801)
                  : (c <= 3807 || (c < 3864
                    ? c == 3840
                    : c <= 3865)))
                : (c <= 3881 || (c < 3897
                  ? (c < 3895
                    ? c == 3893
                    : c <= 3895)
                  : (c <= 3897 || (c < 3913
                    ? (c >= 3902 && c <= 3911)
                    : c <= 3948)))))
              : (c <= 3972 || (c < 4256
                ? (c < 4038
                  ? (c < 3993
                    ? (c >= 3974 && c <= 3991)
                    : c <= 4028)
                  : (c <= 4038 || (c < 4176
                    ? (c >= 4096 && c <= 4169)
                    : c <= 4253)))
                : (c <= 4293 || (c < 4304
                  ? (c < 4301
                    ? c == 4295
                    : c <= 4301)
                  : (c <= 4346 || (c < 4682
                    ? (c >= 4348 && c <= 4680)
                    : c <= 4685)))))))
            : (c <= 4694 || (c < 4882
              ? (c < 4786
                ? (c < 4704
                  ? (c < 4698
                    ? c == 4696
                    : c <= 4701)
                  : (c <= 4744 || (c < 4752
                    ? (c >= 4746 && c <= 4749)
                    : c <= 4784)))
                : (c <= 4789 || (c < 4802
                  ? (c < 4800
                    ? (c >= 4792 && c <= 4798)
                    : c <= 4800)
                  : (c <= 4805 || (c < 4824
                    ? (c >= 4808 && c <= 4822)
                    : c <= 4880)))))
              : (c <= 4885 || (c < 5112
                ? (c < 4969
                  ? (c < 4957
                    ? (c >= 4888 && c <= 4954)
                    : c <= 4959)
                  : (c <= 4977 || (c < 5024
                    ? (c >= 4992 && c <= 5007)
                    : c <= 5109)))
                : (c <= 5117 || (c < 5761
                  ? (c < 5743
                    ? (c >= 5121 && c <= 5740)
                    : c <= 5759)
                  : (c <= 5786 || (c < 5870
                    ? (c >= 5792 && c <= 5866)
                    : c <= 5880)))))))))
          : (c <= 5909 || (c < 6688
            ? (c < 6176
              ? (c < 6016
                ? (c < 5984
                  ? (c < 5952
                    ? (c >= 5919 && c <= 5940)
                    : c <= 5971)
                  : (c <= 5996 || (c < 6002
                    ? (c >= 5998 && c <= 6000)
                    : c <= 6003)))
                : (c <= 6099 || (c < 6112
                  ? (c < 6108
                    ? c == 6103
                    : c <= 6109)
                  : (c <= 6121 || (c < 6159
                    ? (c >= 6155 && c <= 6157)
                    : c <= 6169)))))
              : (c <= 6264 || (c < 6470
                ? (c < 6400
                  ? (c < 6320
                    ? (c >= 6272 && c <= 6314)
                    : c <= 6389)
                  : (c <= 6430 || (c < 6448
                    ? (c >= 6432 && c <= 6443)
                    : c <= 6459)))
                : (c <= 6509 || (c < 6576
                  ? (c < 6528
                    ? (c >= 6512 && c <= 6516)
                    : c <= 6571)
                  : (c <= 6601 || (c < 6656
                    ? (c >= 6608 && c <= 6618)
                    : c <= 6683)))))))
            : (c <= 6750 || (c < 7232
              ? (c < 6847
                ? (c < 6800
                  ? (c < 6783
                    ? (c >= 6752 && c <= 6780)
                    : c <= 6793)
                  : (c <= 6809 || (c < 6832
                    ? c == 6823
                    : c <= 6845)))
                : (c <= 6862 || (c < 7019
                  ? (c < 6992
                    ? (c >= 6912 && c <= 6988)
                    : c <= 7001)
                  : (c <= 7027 || (c < 7168
                    ? (c >= 7040 && c <= 7155)
                    : c <= 7223)))))
              : (c <= 7241 || (c < 7380
                ? (c < 7312
                  ? (c < 7296
                    ? (c >= 7245 && c <= 7293)
                    : c <= 7304)
                  : (c <= 7354 || (c < 7376
                    ? (c >= 7357 && c <= 7359)
                    : c <= 7378)))
                : (c <= 7418 || (c < 7968
                  ? (c < 7960
                    ? (c >= 7424 && c <= 7957)
                    : c <= 7965)
                  : (c <= 8005 || (c < 8016
                    ? (c >= 8008 && c <= 8013)
                    : c <= 8023)))))))))))
        : (c <= 8025 || (c < 11720
          ? (c < 8458
            ? (c < 8178
              ? (c < 8126
                ? (c < 8031
                  ? (c < 8029
                    ? c == 8027
                    : c <= 8029)
                  : (c <= 8061 || (c < 8118
                    ? (c >= 8064 && c <= 8116)
                    : c <= 8124)))
                : (c <= 8126 || (c < 8144
                  ? (c < 8134
                    ? (c >= 8130 && c <= 8132)
                    : c <= 8140)
                  : (c <= 8147 || (c < 8160
                    ? (c >= 8150 && c <= 8155)
                    : c <= 8172)))))
              : (c <= 8180 || (c < 8336
                ? (c < 8276
                  ? (c < 8255
                    ? (c >= 8182 && c <= 8188)
                    : c <= 8256)
                  : (c <= 8276 || (c < 8319
                    ? c == 8305
                    : c <= 8319)))
                : (c <= 8348 || (c < 8421
                  ? (c < 8417
                    ? (c >= 8400 && c <= 8412)
                    : c <= 8417)
                  : (c <= 8432 || (c < 8455
                    ? c == 8450
                    : c <= 8455)))))))
            : (c <= 8467 || (c < 11499
              ? (c < 8490
                ? (c < 8484
                  ? (c < 8472
                    ? c == 8469
                    : c <= 8477)
                  : (c <= 8484 || (c < 8488
                    ? c == 8486
                    : c <= 8488)))
                : (c <= 8505 || (c < 8526
                  ? (c < 8517
                    ? (c >= 8508 && c <= 8511)
                    : c <= 8521)
                  : (c <= 8526 || (c < 11264
                    ? (c >= 8544 && c <= 8584)
                    : c <= 11492)))))
              : (c <= 11507 || (c < 11647
                ? (c < 11565
                  ? (c < 11559
                    ? (c >= 11520 && c <= 11557)
                    : c <= 11559)
                  : (c <= 11565 || (c < 11631
                    ? (c >= 11568 && c <= 11623)
                    : c <= 11631)))
                : (c <= 11670 || (c < 11696
                  ? (c < 11688
                    ? (c >= 11680 && c <= 11686)
                    : c <= 11694)
                  : (c <= 11702 || (c < 11712
                    ? (c >= 11704 && c <= 11710)
                    : c <= 11718)))))))))
          : (c <= 11726 || (c < 42623
            ? (c < 12540
              ? (c < 12337
                ? (c < 11744
                  ? (c < 11736
                    ? (c >= 11728 && c <= 11734)
                    : c <= 11742)
                  : (c <= 11775 || (c < 12321
                    ? (c >= 12293 && c <= 12295)
                    : c <= 12335)))
                : (c <= 12341 || (c < 12441
                  ? (c < 12353
                    ? (c >= 12344 && c <= 12348)
                    : c <= 12438)
                  : (c <= 12442 || (c < 12449
                    ? (c >= 12445 && c <= 12447)
                    : c <= 12538)))))
              : (c <= 12543 || (c < 19968
                ? (c < 12704
                  ? (c < 12593
                    ? (c >= 12549 && c <= 12591)
                    : c <= 12686)
                  : (c <= 12735 || (c < 13312
                    ? (c >= 12784 && c <= 12799)
                    : c <= 19903)))
                : (c <= 42124 || (c < 42512
                  ? (c < 42240
                    ? (c >= 42192 && c <= 42237)
                    : c <= 42508)
                  : (c <= 42539 || (c < 42612
                    ? (c >= 42560 && c <= 42607)
                    : c <= 42621)))))))
            : (c <= 42737 || (c < 43232
              ? (c < 42965
                ? (c < 42891
                  ? (c < 42786
                    ? (c >= 42775 && c <= 42783)
                    : c <= 42888)
                  : (c <= 42954 || (c < 42963
                    ? (c >= 42960 && c <= 42961)
                    : c <= 42963)))
                : (c <= 42969 || (c < 43072
                  ? (c < 43052
                    ? (c >= 42994 && c <= 43047)
                    : c <= 43052)
                  : (c <= 43123 || (c < 43216
                    ? (c >= 43136 && c <= 43205)
                    : c <= 43225)))))
              : (c <= 43255 || (c < 43471
                ? (c < 43312
                  ? (c < 43261
                    ? c == 43259
                    : c <= 43309)
                  : (c <= 43347 || (c < 43392
                    ? (c >= 43360 && c <= 43388)
                    : c <= 43456)))
                : (c <= 43481 || (c < 43584
                  ? (c < 43520
                    ? (c >= 43488 && c <= 43518)
                    : c <= 43574)
                  : (c <= 43597 || (c >= 43600 && c <= 43609)))))))))))))))
    : (c <= 43638 || (c < 71453
      ? (c < 67639
        ? (c < 65345
          ? (c < 64312
            ? (c < 43888
              ? (c < 43785
                ? (c < 43744
                  ? (c < 43739
                    ? (c >= 43642 && c <= 43714)
                    : c <= 43741)
                  : (c <= 43759 || (c < 43777
                    ? (c >= 43762 && c <= 43766)
                    : c <= 43782)))
                : (c <= 43790 || (c < 43816
                  ? (c < 43808
                    ? (c >= 43793 && c <= 43798)
                    : c <= 43814)
                  : (c <= 43822 || (c < 43868
                    ? (c >= 43824 && c <= 43866)
                    : c <= 43881)))))
              : (c <= 44010 || (c < 63744
                ? (c < 44032
                  ? (c < 44016
                    ? (c >= 44012 && c <= 44013)
                    : c <= 44025)
                  : (c <= 55203 || (c < 55243
                    ? (c >= 55216 && c <= 55238)
                    : c <= 55291)))
                : (c <= 64109 || (c < 64275
                  ? (c < 64256
                    ? (c >= 64112 && c <= 64217)
                    : c <= 64262)
                  : (c <= 64279 || (c < 64298
                    ? (c >= 64285 && c <= 64296)
                    : c <= 64310)))))))
            : (c <= 64316 || (c < 65075
              ? (c < 64612
                ? (c < 64323
                  ? (c < 64320
                    ? c == 64318
                    : c <= 64321)
                  : (c <= 64324 || (c < 64467
                    ? (c >= 64326 && c <= 64433)
                    : c <= 64605)))
                : (c <= 64829 || (c < 65008
                  ? (c < 64914
                    ? (c >= 64848 && c <= 64911)
                    : c <= 64967)
                  : (c <= 65017 || (c < 65056
                    ? (c >= 65024 && c <= 65039)
                    : c <= 65071)))))
              : (c <= 65076 || (c < 65147
                ? (c < 65139
                  ? (c < 65137
                    ? (c >= 65101 && c <= 65103)
                    : c <= 65137)
                  : (c <= 65139 || (c < 65145
                    ? c == 65143
                    : c <= 65145)))
                : (c <= 65147 || (c < 65296
                  ? (c < 65151
                    ? c == 65149
                    : c <= 65276)
                  : (c <= 65305 || (c < 65343
                    ? (c >= 65313 && c <= 65338)
                    : c <= 65343)))))))))
          : (c <= 65370 || (c < 66513
            ? (c < 65664
              ? (c < 65536
                ? (c < 65482
                  ? (c < 65474
                    ? (c >= 65382 && c <= 65470)
                    : c <= 65479)
                  : (c <= 65487 || (c < 65498
                    ? (c >= 65490 && c <= 65495)
                    : c <= 65500)))
                : (c <= 65547 || (c < 65596
                  ? (c < 65576
                    ? (c >= 65549 && c <= 65574)
                    : c <= 65594)
                  : (c <= 65597 || (c < 65616
                    ? (c >= 65599 && c <= 65613)
                    : c <= 65629)))))
              : (c <= 65786 || (c < 66304
                ? (c < 66176
                  ? (c < 66045
                    ? (c >= 65856 && c <= 65908)
                    : c <= 66045)
                  : (c <= 66204 || (c < 66272
                    ? (c >= 66208 && c <= 66256)
                    : c <= 66272)))
                : (c <= 66335 || (c < 66432
                  ? (c < 66384
                    ? (c >= 66349 && c <= 66378)
                    : c <= 66426)
                  : (c <= 66461 || (c < 66504
                    ? (c >= 66464 && c <= 66499)
                    : c <= 66511)))))))
            : (c <= 66517 || (c < 66979
              ? (c < 66864
                ? (c < 66736
                  ? (c < 66720
                    ? (c >= 66560 && c <= 66717)
                    : c <= 66729)
                  : (c <= 66771 || (c < 66816
                    ? (c >= 66776 && c <= 66811)
                    : c <= 66855)))
                : (c <= 66915 || (c < 66956
                  ? (c < 66940
                    ? (c >= 66928 && c <= 66938)
                    : c <= 66954)
                  : (c <= 66962 || (c < 66967
                    ? (c >= 66964 && c <= 66965)
                    : c <= 66977)))))
              : (c <= 66993 || (c < 67456
                ? (c < 67072
                  ? (c < 67003
                    ? (c >= 66995 && c <= 67001)
                    : c <= 67004)
                  : (c <= 67382 || (c < 67424
                    ? (c >= 67392 && c <= 67413)
                    : c <= 67431)))
                : (c <= 67461 || (c < 67584
                  ? (c < 67506
                    ? (c >= 67463 && c <= 67504)
                    : c <= 67514)
                  : (c <= 67589 || (c < 67594
                    ? c == 67592
                    : c <= 67637)))))))))))
        : (c <= 67640 || (c < 69956
          ? (c < 68448
            ? (c < 68101
              ? (c < 67828
                ? (c < 67680
                  ? (c < 67647
                    ? c == 67644
                    : c <= 67669)
                  : (c <= 67702 || (c < 67808
                    ? (c >= 67712 && c <= 67742)
                    : c <= 67826)))
                : (c <= 67829 || (c < 67968
                  ? (c < 67872
                    ? (c >= 67840 && c <= 67861)
                    : c <= 67897)
                  : (c <= 68023 || (c < 68096
                    ? (c >= 68030 && c <= 68031)
                    : c <= 68099)))))
              : (c <= 68102 || (c < 68192
                ? (c < 68121
                  ? (c < 68117
                    ? (c >= 68108 && c <= 68115)
                    : c <= 68119)
                  : (c <= 68149 || (c < 68159
                    ? (c >= 68152 && c <= 68154)
                    : c <= 68159)))
                : (c <= 68220 || (c < 68297
                  ? (c < 68288
                    ? (c >= 68224 && c <= 68252)
                    : c <= 68295)
                  : (c <= 68326 || (c < 68416
                    ? (c >= 68352 && c <= 68405)
                    : c <= 68437)))))))
            : (c <= 68466 || (c < 69424
              ? (c < 68912
                ? (c < 68736
                  ? (c < 68608
                    ? (c >= 68480 && c <= 68497)
                    : c <= 68680)
                  : (c <= 68786 || (c < 68864
                    ? (c >= 68800 && c <= 68850)
                    : c <= 68903)))
                : (c <= 68921 || (c < 69296
                  ? (c < 69291
                    ? (c >= 69248 && c <= 69289)
                    : c <= 69292)
                  : (c <= 69297 || (c < 69415
                    ? (c >= 69376 && c <= 69404)
                    : c <= 69415)))))
              : (c <= 69456 || (c < 69759
                ? (c < 69600
                  ? (c < 69552
                    ? (c >= 69488 && c <= 69509)
                    : c <= 69572)
                  : (c <= 69622 || (c < 69734
                    ? (c >= 69632 && c <= 69702)
                    : c <= 69749)))
                : (c <= 69818 || (c < 69872
                  ? (c < 69840
                    ? c == 69826
                    : c <= 69864)
                  : (c <= 69881 || (c < 69942
                    ? (c >= 69888 && c <= 69940)
                    : c <= 69951)))))))))
          : (c <= 69959 || (c < 70459
            ? (c < 70282
              ? (c < 70108
                ? (c < 70016
                  ? (c < 70006
                    ? (c >= 69968 && c <= 70003)
                    : c <= 70006)
                  : (c <= 70084 || (c < 70094
                    ? (c >= 70089 && c <= 70092)
                    : c <= 70106)))
                : (c <= 70108 || (c < 70206
                  ? (c < 70163
                    ? (c >= 70144 && c <= 70161)
                    : c <= 70199)
                  : (c <= 70206 || (c < 70280
                    ? (c >= 70272 && c <= 70278)
                    : c <= 70280)))))
              : (c <= 70285 || (c < 70405
                ? (c < 70320
                  ? (c < 70303
                    ? (c >= 70287 && c <= 70301)
                    : c <= 70312)
                  : (c <= 70378 || (c < 70400
                    ? (c >= 70384 && c <= 70393)
                    : c <= 70403)))
                : (c <= 70412 || (c < 70442
                  ? (c < 70419
                    ? (c >= 70415 && c <= 70416)
                    : c <= 70440)
                  : (c <= 70448 || (c < 70453
                    ? (c >= 70450 && c <= 70451)
                    : c <= 70457)))))))
            : (c <= 70468 || (c < 70855
              ? (c < 70502
                ? (c < 70480
                  ? (c < 70475
                    ? (c >= 70471 && c <= 70472)
                    : c <= 70477)
                  : (c <= 70480 || (c < 70493
                    ? c == 70487
                    : c <= 70499)))
                : (c <= 70508 || (c < 70736
                  ? (c < 70656
                    ? (c >= 70512 && c <= 70516)
                    : c <= 70730)
                  : (c <= 70745 || (c < 70784
                    ? (c >= 70750 && c <= 70753)
                    : c <= 70853)))))
              : (c <= 70855 || (c < 71236
                ? (c < 71096
                  ? (c < 71040
                    ? (c >= 70864 && c <= 70873)
                    : c <= 71093)
                  : (c <= 71104 || (c < 71168
                    ? (c >= 71128 && c <= 71133)
                    : c <= 71232)))
                : (c <= 71236 || (c < 71360
                  ? (c < 71296
                    ? (c >= 71248 && c <= 71257)
                    : c <= 71352)
                  : (c <= 71369 || (c >= 71424 && c <= 71450)))))))))))))
      : (c <= 71467 || (c < 119973
        ? (c < 77824
          ? (c < 72760
            ? (c < 72016
              ? (c < 71945
                ? (c < 71680
                  ? (c < 71488
                    ? (c >= 71472 && c <= 71481)
                    : c <= 71494)
                  : (c <= 71738 || (c < 71935
                    ? (c >= 71840 && c <= 71913)
                    : c <= 71942)))
                : (c <= 71945 || (c < 71960
                  ? (c < 71957
                    ? (c >= 71948 && c <= 71955)
                    : c <= 71958)
                  : (c <= 71989 || (c < 71995
                    ? (c >= 71991 && c <= 71992)
                    : c <= 72003)))))
              : (c <= 72025 || (c < 72263
                ? (c < 72154
                  ? (c < 72106
                    ? (c >= 72096 && c <= 72103)
                    : c <= 72151)
                  : (c <= 72161 || (c < 72192
                    ? (c >= 72163 && c <= 72164)
                    : c <= 72254)))
                : (c <= 72263 || (c < 72368
                  ? (c < 72349
                    ? (c >= 72272 && c <= 72345)
                    : c <= 72349)
                  : (c <= 72440 || (c < 72714
                    ? (c >= 72704 && c <= 72712)
                    : c <= 72758)))))))
            : (c <= 72768 || (c < 73056
              ? (c < 72968
                ? (c < 72850
                  ? (c < 72818
                    ? (c >= 72784 && c <= 72793)
                    : c <= 72847)
                  : (c <= 72871 || (c < 72960
                    ? (c >= 72873 && c <= 72886)
                    : c <= 72966)))
                : (c <= 72969 || (c < 73020
                  ? (c < 73018
                    ? (c >= 72971 && c <= 73014)
                    : c <= 73018)
                  : (c <= 73021 || (c < 73040
                    ? (c >= 73023 && c <= 73031)
                    : c <= 73049)))))
              : (c <= 73061 || (c < 73440
                ? (c < 73104
                  ? (c < 73066
                    ? (c >= 73063 && c <= 73064)
                    : c <= 73102)
                  : (c <= 73105 || (c < 73120
                    ? (c >= 73107 && c <= 73112)
                    : c <= 73129)))
                : (c <= 73462 || (c < 74752
                  ? (c < 73728
                    ? c == 73648
                    : c <= 74649)
                  : (c <= 74862 || (c < 77712
                    ? (c >= 74880 && c <= 75075)
                    : c <= 77808)))))))))
          : (c <= 78894 || (c < 110576
            ? (c < 93027
              ? (c < 92864
                ? (c < 92736
                  ? (c < 92160
                    ? (c >= 82944 && c <= 83526)
                    : c <= 92728)
                  : (c <= 92766 || (c < 92784
                    ? (c >= 92768 && c <= 92777)
                    : c <= 92862)))
                : (c <= 92873 || (c < 92928
                  ? (c < 92912
                    ? (c >= 92880 && c <= 92909)
                    : c <= 92916)
                  : (c <= 92982 || (c < 93008
                    ? (c >= 92992 && c <= 92995)
                    : c <= 93017)))))
              : (c <= 93047 || (c < 94176
                ? (c < 93952
                  ? (c < 93760
                    ? (c >= 93053 && c <= 93071)
                    : c <= 93823)
                  : (c <= 94026 || (c < 94095
                    ? (c >= 94031 && c <= 94087)
                    : c <= 94111)))
                : (c <= 94177 || (c < 94208
                  ? (c < 94192
                    ? (c >= 94179 && c <= 94180)
                    : c <= 94193)
                  : (c <= 100343 || (c < 101632
                    ? (c >= 100352 && c <= 101589)
                    : c <= 101640)))))))
            : (c <= 110579 || (c < 118528
              ? (c < 110960
                ? (c < 110592
                  ? (c < 110589
                    ? (c >= 110581 && c <= 110587)
                    : c <= 110590)
                  : (c <= 110882 || (c < 110948
                    ? (c >= 110928 && c <= 110930)
                    : c <= 110951)))
                : (c <= 111355 || (c < 113792
                  ? (c < 113776
                    ? (c >= 113664 && c <= 113770)
                    : c <= 113788)
                  : (c <= 113800 || (c < 113821
                    ? (c >= 113808 && c <= 113817)
                    : c <= 113822)))))
              : (c <= 118573 || (c < 119210
                ? (c < 119149
                  ? (c < 119141
                    ? (c >= 118576 && c <= 118598)
                    : c <= 119145)
                  : (c <= 119154 || (c < 119173
                    ? (c >= 119163 && c <= 119170)
                    : c <= 119179)))
                : (c <= 119213 || (c < 119894
                  ? (c < 119808
                    ? (c >= 119362 && c <= 119364)
                    : c <= 119892)
                  : (c <= 119964 || (c < 119970
                    ? (c >= 119966 && c <= 119967)
                    : c <= 119970)))))))))))
        : (c <= 119974 || (c < 124912
          ? (c < 120746
            ? (c < 120134
              ? (c < 120071
                ? (c < 119995
                  ? (c < 119982
                    ? (c >= 119977 && c <= 119980)
                    : c <= 119993)
                  : (c <= 119995 || (c < 120005
                    ? (c >= 119997 && c <= 120003)
                    : c <= 120069)))
                : (c <= 120074 || (c < 120094
                  ? (c < 120086
                    ? (c >= 120077 && c <= 120084)
                    : c <= 120092)
                  : (c <= 120121 || (c < 120128
                    ? (c >= 120123 && c <= 120126)
                    : c <= 120132)))))
              : (c <= 120134 || (c < 120572
                ? (c < 120488
                  ? (c < 120146
                    ? (c >= 120138 && c <= 120144)
                    : c <= 120485)
                  : (c <= 120512 || (c < 120540
                    ? (c >= 120514 && c <= 120538)
                    : c <= 120570)))
                : (c <= 120596 || (c < 120656
                  ? (c < 120630
                    ? (c >= 120598 && c <= 120628)
                    : c <= 120654)
                  : (c <= 120686 || (c < 120714
                    ? (c >= 120688 && c <= 120712)
                    : c <= 120744)))))))
            : (c <= 120770 || (c < 122907
              ? (c < 121476
                ? (c < 121344
                  ? (c < 120782
                    ? (c >= 120772 && c <= 120779)
                    : c <= 120831)
                  : (c <= 121398 || (c < 121461
                    ? (c >= 121403 && c <= 121452)
                    : c <= 121461)))
                : (c <= 121476 || (c < 122624
                  ? (c < 121505
                    ? (c >= 121499 && c <= 121503)
                    : c <= 121519)
                  : (c <= 122654 || (c < 122888
                    ? (c >= 122880 && c <= 122886)
                    : c <= 122904)))))
              : (c <= 122913 || (c < 123214
                ? (c < 123136
                  ? (c < 122918
                    ? (c >= 122915 && c <= 122916)
                    : c <= 122922)
                  : (c <= 123180 || (c < 123200
                    ? (c >= 123184 && c <= 123197)
                    : c <= 123209)))
                : (c <= 123214 || (c < 124896
                  ? (c < 123584
                    ? (c >= 123536 && c <= 123566)
                    : c <= 123641)
                  : (c <= 124902 || (c < 124909
                    ? (c >= 124904 && c <= 124907)
                    : c <= 124910)))))))))
          : (c <= 124926 || (c < 126557
            ? (c < 126521
              ? (c < 126469
                ? (c < 125184
                  ? (c < 125136
                    ? (c >= 124928 && c <= 125124)
                    : c <= 125142)
                  : (c <= 125259 || (c < 126464
                    ? (c >= 125264 && c <= 125273)
                    : c <= 126467)))
                : (c <= 126495 || (c < 126503
                  ? (c < 126500
                    ? (c >= 126497 && c <= 126498)
                    : c <= 126500)
                  : (c <= 126503 || (c < 126516
                    ? (c >= 126505 && c <= 126514)
                    : c <= 126519)))))
              : (c <= 126521 || (c < 126541
                ? (c < 126535
                  ? (c < 126530
                    ? c == 126523
                    : c <= 126530)
                  : (c <= 126535 || (c < 126539
                    ? c == 126537
                    : c <= 126539)))
                : (c <= 126543 || (c < 126551
                  ? (c < 126548
                    ? (c >= 126545 && c <= 126546)
                    : c <= 126548)
                  : (c <= 126551 || (c < 126555
                    ? c == 126553
                    : c <= 126555)))))))
            : (c <= 126557 || (c < 126629
              ? (c < 126580
                ? (c < 126564
                  ? (c < 126561
                    ? c == 126559
                    : c <= 126562)
                  : (c <= 126564 || (c < 126572
                    ? (c >= 126567 && c <= 126570)
                    : c <= 126578)))
                : (c <= 126583 || (c < 126592
                  ? (c < 126590
                    ? (c >= 126585 && c <= 126588)
                    : c <= 126590)
                  : (c <= 126601 || (c < 126625
                    ? (c >= 126603 && c <= 126619)
                    : c <= 126627)))))
              : (c <= 126633 || (c < 178208
                ? (c < 131072
                  ? (c < 130032
                    ? (c >= 126635 && c <= 126651)
                    : c <= 130041)
                  : (c <= 173791 || (c < 177984
                    ? (c >= 173824 && c <= 177976)
                    : c <= 178205)))
                : (c <= 183969 || (c < 196608
                  ? (c < 194560
                    ? (c >= 183984 && c <= 191456)
                    : c <= 195101)
                  : (c <= 201546 || (c >= 917760 && c <= 917999)))))))))))))))));
}

static inline bool sym_identifier_character_set_5(int32_t c) {
  return (c < 43616
    ? (c < 3782
      ? (c < 2748
        ? (c < 2045
          ? (c < 1015
            ? (c < 710
              ? (c < 181
                ? (c < '_'
                  ? (c < 'A'
                    ? (c >= '0' && c <= '9')
                    : c <= 'Z')
                  : (c <= '_' || (c < 170
                    ? (c >= 'b' && c <= 'z')
                    : c <= 170)))
                : (c <= 181 || (c < 192
                  ? (c < 186
                    ? c == 183
                    : c <= 186)
                  : (c <= 214 || (c < 248
                    ? (c >= 216 && c <= 246)
                    : c <= 705)))))
              : (c <= 721 || (c < 891
                ? (c < 750
                  ? (c < 748
                    ? (c >= 736 && c <= 740)
                    : c <= 748)
                  : (c <= 750 || (c < 886
                    ? (c >= 768 && c <= 884)
                    : c <= 887)))
                : (c <= 893 || (c < 908
                  ? (c < 902
                    ? c == 895
                    : c <= 906)
                  : (c <= 908 || (c < 931
                    ? (c >= 910 && c <= 929)
                    : c <= 1013)))))))
            : (c <= 1153 || (c < 1519
              ? (c < 1425
                ? (c < 1329
                  ? (c < 1162
                    ? (c >= 1155 && c <= 1159)
                    : c <= 1327)
                  : (c <= 1366 || (c < 1376
                    ? c == 1369
                    : c <= 1416)))
                : (c <= 1469 || (c < 1476
                  ? (c < 1473
                    ? c == 1471
                    : c <= 1474)
                  : (c <= 1477 || (c < 1488
                    ? c == 1479
                    : c <= 1514)))))
              : (c <= 1522 || (c < 1770
                ? (c < 1646
                  ? (c < 1568
                    ? (c >= 1552 && c <= 1562)
                    : c <= 1641)
                  : (c <= 1747 || (c < 1759
                    ? (c >= 1749 && c <= 1756)
                    : c <= 1768)))
                : (c <= 1788 || (c < 1869
                  ? (c < 1808
                    ? c == 1791
                    : c <= 1866)
                  : (c <= 1969 || (c < 2042
                    ? (c >= 1984 && c <= 2037)
                    : c <= 2042)))))))))
          : (c <= 2045 || (c < 2558
            ? (c < 2451
              ? (c < 2200
                ? (c < 2144
                  ? (c < 2112
                    ? (c >= 2048 && c <= 2093)
                    : c <= 2139)
                  : (c <= 2154 || (c < 2185
                    ? (c >= 2160 && c <= 2183)
                    : c <= 2190)))
                : (c <= 2273 || (c < 2417
                  ? (c < 2406
                    ? (c >= 2275 && c <= 2403)
                    : c <= 2415)
                  : (c <= 2435 || (c < 2447
                    ? (c >= 2437 && c <= 2444)
                    : c <= 2448)))))
              : (c <= 2472 || (c < 2507
                ? (c < 2486
                  ? (c < 2482
                    ? (c >= 2474 && c <= 2480)
                    : c <= 2482)
                  : (c <= 2489 || (c < 2503
                    ? (c >= 2492 && c <= 2500)
                    : c <= 2504)))
                : (c <= 2510 || (c < 2527
                  ? (c < 2524
                    ? c == 2519
                    : c <= 2525)
                  : (c <= 2531 || (c < 2556
                    ? (c >= 2534 && c <= 2545)
                    : c <= 2556)))))))
            : (c <= 2558 || (c < 2635
              ? (c < 2610
                ? (c < 2575
                  ? (c < 2565
                    ? (c >= 2561 && c <= 2563)
                    : c <= 2570)
                  : (c <= 2576 || (c < 2602
                    ? (c >= 2579 && c <= 2600)
                    : c <= 2608)))
                : (c <= 2611 || (c < 2620
                  ? (c < 2616
                    ? (c >= 2613 && c <= 2614)
                    : c <= 2617)
                  : (c <= 2620 || (c < 2631
                    ? (c >= 2622 && c <= 2626)
                    : c <= 2632)))))
              : (c <= 2637 || (c < 2693
                ? (c < 2654
                  ? (c < 2649
                    ? c == 2641
                    : c <= 2652)
                  : (c <= 2654 || (c < 2689
                    ? (c >= 2662 && c <= 2677)
                    : c <= 2691)))
                : (c <= 2701 || (c < 2730
                  ? (c < 2707
                    ? (c >= 2703 && c <= 2705)
                    : c <= 2728)
                  : (c <= 2736 || (c < 2741
                    ? (c >= 2738 && c <= 2739)
                    : c <= 2745)))))))))))
        : (c <= 2757 || (c < 3168
          ? (c < 2958
            ? (c < 2866
              ? (c < 2809
                ? (c < 2768
                  ? (c < 2763
                    ? (c >= 2759 && c <= 2761)
                    : c <= 2765)
                  : (c <= 2768 || (c < 2790
                    ? (c >= 2784 && c <= 2787)
                    : c <= 2799)))
                : (c <= 2815 || (c < 2831
                  ? (c < 2821
                    ? (c >= 2817 && c <= 2819)
                    : c <= 2828)
                  : (c <= 2832 || (c < 2858
                    ? (c >= 2835 && c <= 2856)
                    : c <= 2864)))))
              : (c <= 2867 || (c < 2908
                ? (c < 2887
                  ? (c < 2876
                    ? (c >= 2869 && c <= 2873)
                    : c <= 2884)
                  : (c <= 2888 || (c < 2901
                    ? (c >= 2891 && c <= 2893)
                    : c <= 2903)))
                : (c <= 2909 || (c < 2929
                  ? (c < 2918
                    ? (c >= 2911 && c <= 2915)
                    : c <= 2927)
                  : (c <= 2929 || (c < 2949
                    ? (c >= 2946 && c <= 2947)
                    : c <= 2954)))))))
            : (c <= 2960 || (c < 3031
              ? (c < 2984
                ? (c < 2972
                  ? (c < 2969
                    ? (c >= 2962 && c <= 2965)
                    : c <= 2970)
                  : (c <= 2972 || (c < 2979
                    ? (c >= 2974 && c <= 2975)
                    : c <= 2980)))
                : (c <= 2986 || (c < 3014
                  ? (c < 3006
                    ? (c >= 2990 && c <= 3001)
                    : c <= 3010)
                  : (c <= 3016 || (c < 3024
                    ? (c >= 3018 && c <= 3021)
                    : c <= 3024)))))
              : (c <= 3031 || (c < 3132
                ? (c < 3086
                  ? (c < 3072
                    ? (c >= 3046 && c <= 3055)
                    : c <= 3084)
                  : (c <= 3088 || (c < 3114
                    ? (c >= 3090 && c <= 3112)
                    : c <= 3129)))
                : (c <= 3140 || (c < 3157
                  ? (c < 3146
                    ? (c >= 3142 && c <= 3144)
                    : c <= 3149)
                  : (c <= 3158 || (c < 3165
                    ? (c >= 3160 && c <= 3162)
                    : c <= 3165)))))))))
          : (c <= 3171 || (c < 3450
            ? (c < 3293
              ? (c < 3242
                ? (c < 3205
                  ? (c < 3200
                    ? (c >= 3174 && c <= 3183)
                    : c <= 3203)
                  : (c <= 3212 || (c < 3218
                    ? (c >= 3214 && c <= 3216)
                    : c <= 3240)))
                : (c <= 3251 || (c < 3270
                  ? (c < 3260
                    ? (c >= 3253 && c <= 3257)
                    : c <= 3268)
                  : (c <= 3272 || (c < 3285
                    ? (c >= 3274 && c <= 3277)
                    : c <= 3286)))))
              : (c <= 3294 || (c < 3346
                ? (c < 3313
                  ? (c < 3302
                    ? (c >= 3296 && c <= 3299)
                    : c <= 3311)
                  : (c <= 3314 || (c < 3342
                    ? (c >= 3328 && c <= 3340)
                    : c <= 3344)))
                : (c <= 3396 || (c < 3412
                  ? (c < 3402
                    ? (c >= 3398 && c <= 3400)
                    : c <= 3406)
                  : (c <= 3415 || (c < 3430
                    ? (c >= 3423 && c <= 3427)
                    : c <= 3439)))))))
            : (c <= 3455 || (c < 3570
              ? (c < 3520
                ? (c < 3482
                  ? (c < 3461
                    ? (c >= 3457 && c <= 3459)
                    : c <= 3478)
                  : (c <= 3505 || (c < 3517
                    ? (c >= 3507 && c <= 3515)
                    : c <= 3517)))
                : (c <= 3526 || (c < 3542
                  ? (c < 3535
                    ? c == 3530
                    : c <= 3540)
                  : (c <= 3542 || (c < 3558
                    ? (c >= 3544 && c <= 3551)
                    : c <= 3567)))))
              : (c <= 3571 || (c < 3718
                ? (c < 3664
                  ? (c < 3648
                    ? (c >= 3585 && c <= 3642)
                    : c <= 3662)
                  : (c <= 3673 || (c < 3716
                    ? (c >= 3713 && c <= 3714)
                    : c <= 3716)))
                : (c <= 3722 || (c < 3751
                  ? (c < 3749
                    ? (c >= 3724 && c <= 3747)
                    : c <= 3749)
                  : (c <= 3773 || (c >= 3776 && c <= 3780)))))))))))))
      : (c <= 3782 || (c < 8025
        ? (c < 5888
          ? (c < 4688
            ? (c < 3953
              ? (c < 3872
                ? (c < 3804
                  ? (c < 3792
                    ? (c >= 3784 && c <= 3789)
                    : c <= 3801)
                  : (c <= 3807 || (c < 3864
                    ? c == 3840
                    : c <= 3865)))
                : (c <= 3881 || (c < 3897
                  ? (c < 3895
                    ? c == 3893
                    : c <= 3895)
                  : (c <= 3897 || (c < 3913
                    ? (c >= 3902 && c <= 3911)
                    : c <= 3948)))))
              : (c <= 3972 || (c < 4256
                ? (c < 4038
                  ? (c < 3993
                    ? (c >= 3974 && c <= 3991)
                    : c <= 4028)
                  : (c <= 4038 || (c < 4176
                    ? (c >= 4096 && c <= 4169)
                    : c <= 4253)))
                : (c <= 4293 || (c < 4304
                  ? (c < 4301
                    ? c == 4295
                    : c <= 4301)
                  : (c <= 4346 || (c < 4682
                    ? (c >= 4348 && c <= 4680)
                    : c <= 4685)))))))
            : (c <= 4694 || (c < 4882
              ? (c < 4786
                ? (c < 4704
                  ? (c < 4698
                    ? c == 4696
                    : c <= 4701)
                  : (c <= 4744 || (c < 4752
                    ? (c >= 4746 && c <= 4749)
                    : c <= 4784)))
                : (c <= 4789 || (c < 4802
                  ? (c < 4800
                    ? (c >= 4792 && c <= 4798)
                    : c <= 4800)
                  : (c <= 4805 || (c < 4824
                    ? (c >= 4808 && c <= 4822)
                    : c <= 4880)))))
              : (c <= 4885 || (c < 5112
                ? (c < 4969
                  ? (c < 4957
                    ? (c >= 4888 && c <= 4954)
                    : c <= 4959)
                  : (c <= 4977 || (c < 5024
                    ? (c >= 4992 && c <= 5007)
                    : c <= 5109)))
                : (c <= 5117 || (c < 5761
                  ? (c < 5743
                    ? (c >= 5121 && c <= 5740)
                    : c <= 5759)
                  : (c <= 5786 || (c < 5870
                    ? (c >= 5792 && c <= 5866)
                    : c <= 5880)))))))))
          : (c <= 5909 || (c < 6688
            ? (c < 6176
              ? (c < 6016
                ? (c < 5984
                  ? (c < 5952
                    ? (c >= 5919 && c <= 5940)
                    : c <= 5971)
                  : (c <= 5996 || (c < 6002
                    ? (c >= 5998 && c <= 6000)
                    : c <= 6003)))
                : (c <= 6099 || (c < 6112
                  ? (c < 6108
                    ? c == 6103
                    : c <= 6109)
                  : (c <= 6121 || (c < 6159
                    ? (c >= 6155 && c <= 6157)
                    : c <= 6169)))))
              : (c <= 6264 || (c < 6470
                ? (c < 6400
                  ? (c < 6320
                    ? (c >= 6272 && c <= 6314)
                    : c <= 6389)
                  : (c <= 6430 || (c < 6448
                    ? (c >= 6432 && c <= 6443)
                    : c <= 6459)))
                : (c <= 6509 || (c < 6576
                  ? (c < 6528
                    ? (c >= 6512 && c <= 6516)
                    : c <= 6571)
                  : (c <= 6601 || (c < 6656
                    ? (c >= 6608 && c <= 6618)
                    : c <= 6683)))))))
            : (c <= 6750 || (c < 7232
              ? (c < 6847
                ? (c < 6800
                  ? (c < 6783
                    ? (c >= 6752 && c <= 6780)
                    : c <= 6793)
                  : (c <= 6809 || (c < 6832
                    ? c == 6823
                    : c <= 6845)))
                : (c <= 6862 || (c < 7019
                  ? (c < 6992
                    ? (c >= 6912 && c <= 6988)
                    : c <= 7001)
                  : (c <= 7027 || (c < 7168
                    ? (c >= 7040 && c <= 7155)
                    : c <= 7223)))))
              : (c <= 7241 || (c < 7380
                ? (c < 7312
                  ? (c < 7296
                    ? (c >= 7245 && c <= 7293)
                    : c <= 7304)
                  : (c <= 7354 || (c < 7376
                    ? (c >= 7357 && c <= 7359)
                    : c <= 7378)))
                : (c <= 7418 || (c < 7968
                  ? (c < 7960
                    ? (c >= 7424 && c <= 7957)
                    : c <= 7965)
                  : (c <= 8005 || (c < 8016
                    ? (c >= 8008 && c <= 8013)
                    : c <= 8023)))))))))))
        : (c <= 8025 || (c < 11720
          ? (c < 8458
            ? (c < 8178
              ? (c < 8126
                ? (c < 8031
                  ? (c < 8029
                    ? c == 8027
                    : c <= 8029)
                  : (c <= 8061 || (c < 8118
                    ? (c >= 8064 && c <= 8116)
                    : c <= 8124)))
                : (c <= 8126 || (c < 8144
                  ? (c < 8134
                    ? (c >= 8130 && c <= 8132)
                    : c <= 8140)
                  : (c <= 8147 || (c < 8160
                    ? (c >= 8150 && c <= 8155)
                    : c <= 8172)))))
              : (c <= 8180 || (c < 8336
                ? (c < 8276
                  ? (c < 8255
                    ? (c >= 8182 && c <= 8188)
                    : c <= 8256)
                  : (c <= 8276 || (c < 8319
                    ? c == 8305
                    : c <= 8319)))
                : (c <= 8348 || (c < 8421
                  ? (c < 8417
                    ? (c >= 8400 && c <= 8412)
                    : c <= 8417)
                  : (c <= 8432 || (c < 8455
                    ? c == 8450
                    : c <= 8455)))))))
            : (c <= 8467 || (c < 11499
              ? (c < 8490
                ? (c < 8484
                  ? (c < 8472
                    ? c == 8469
                    : c <= 8477)
                  : (c <= 8484 || (c < 8488
                    ? c == 8486
                    : c <= 8488)))
                : (c <= 8505 || (c < 8526
                  ? (c < 8517
                    ? (c >= 8508 && c <= 8511)
                    : c <= 8521)
                  : (c <= 8526 || (c < 11264
                    ? (c >= 8544 && c <= 8584)
                    : c <= 11492)))))
              : (c <= 11507 || (c < 11647
                ? (c < 11565
                  ? (c < 11559
                    ? (c >= 11520 && c <= 11557)
                    : c <= 11559)
                  : (c <= 11565 || (c < 11631
                    ? (c >= 11568 && c <= 11623)
                    : c <= 11631)))
                : (c <= 11670 || (c < 11696
                  ? (c < 11688
                    ? (c >= 11680 && c <= 11686)
                    : c <= 11694)
                  : (c <= 11702 || (c < 11712
                    ? (c >= 11704 && c <= 11710)
                    : c <= 11718)))))))))
          : (c <= 11726 || (c < 42623
            ? (c < 12540
              ? (c < 12337
                ? (c < 11744
                  ? (c < 11736
                    ? (c >= 11728 && c <= 11734)
                    : c <= 11742)
                  : (c <= 11775 || (c < 12321
                    ? (c >= 12293 && c <= 12295)
                    : c <= 12335)))
                : (c <= 12341 || (c < 12441
                  ? (c < 12353
                    ? (c >= 12344 && c <= 12348)
                    : c <= 12438)
                  : (c <= 12442 || (c < 12449
                    ? (c >= 12445 && c <= 12447)
                    : c <= 12538)))))
              : (c <= 12543 || (c < 19968
                ? (c < 12704
                  ? (c < 12593
                    ? (c >= 12549 && c <= 12591)
                    : c <= 12686)
                  : (c <= 12735 || (c < 13312
                    ? (c >= 12784 && c <= 12799)
                    : c <= 19903)))
                : (c <= 42124 || (c < 42512
                  ? (c < 42240
                    ? (c >= 42192 && c <= 42237)
                    : c <= 42508)
                  : (c <= 42539 || (c < 42612
                    ? (c >= 42560 && c <= 42607)
                    : c <= 42621)))))))
            : (c <= 42737 || (c < 43232
              ? (c < 42965
                ? (c < 42891
                  ? (c < 42786
                    ? (c >= 42775 && c <= 42783)
                    : c <= 42888)
                  : (c <= 42954 || (c < 42963
                    ? (c >= 42960 && c <= 42961)
                    : c <= 42963)))
                : (c <= 42969 || (c < 43072
                  ? (c < 43052
                    ? (c >= 42994 && c <= 43047)
                    : c <= 43052)
                  : (c <= 43123 || (c < 43216
                    ? (c >= 43136 && c <= 43205)
                    : c <= 43225)))))
              : (c <= 43255 || (c < 43471
                ? (c < 43312
                  ? (c < 43261
                    ? c == 43259
                    : c <= 43309)
                  : (c <= 43347 || (c < 43392
                    ? (c >= 43360 && c <= 43388)
                    : c <= 43456)))
                : (c <= 43481 || (c < 43584
                  ? (c < 43520
                    ? (c >= 43488 && c <= 43518)
                    : c <= 43574)
                  : (c <= 43597 || (c >= 43600 && c <= 43609)))))))))))))))
    : (c <= 43638 || (c < 71453
      ? (c < 67639
        ? (c < 65345
          ? (c < 64312
            ? (c < 43888
              ? (c < 43785
                ? (c < 43744
                  ? (c < 43739
                    ? (c >= 43642 && c <= 43714)
                    : c <= 43741)
                  : (c <= 43759 || (c < 43777
                    ? (c >= 43762 && c <= 43766)
                    : c <= 43782)))
                : (c <= 43790 || (c < 43816
                  ? (c < 43808
                    ? (c >= 43793 && c <= 43798)
                    : c <= 43814)
                  : (c <= 43822 || (c < 43868
                    ? (c >= 43824 && c <= 43866)
                    : c <= 43881)))))
              : (c <= 44010 || (c < 63744
                ? (c < 44032
                  ? (c < 44016
                    ? (c >= 44012 && c <= 44013)
                    : c <= 44025)
                  : (c <= 55203 || (c < 55243
                    ? (c >= 55216 && c <= 55238)
                    : c <= 55291)))
                : (c <= 64109 || (c < 64275
                  ? (c < 64256
                    ? (c >= 64112 && c <= 64217)
                    : c <= 64262)
                  : (c <= 64279 || (c < 64298
                    ? (c >= 64285 && c <= 64296)
                    : c <= 64310)))))))
            : (c <= 64316 || (c < 65075
              ? (c < 64612
                ? (c < 64323
                  ? (c < 64320
                    ? c == 64318
                    : c <= 64321)
                  : (c <= 64324 || (c < 64467
                    ? (c >= 64326 && c <= 64433)
                    : c <= 64605)))
                : (c <= 64829 || (c < 65008
                  ? (c < 64914
                    ? (c >= 64848 && c <= 64911)
                    : c <= 64967)
                  : (c <= 65017 || (c < 65056
                    ? (c >= 65024 && c <= 65039)
                    : c <= 65071)))))
              : (c <= 65076 || (c < 65147
                ? (c < 65139
                  ? (c < 65137
                    ? (c >= 65101 && c <= 65103)
                    : c <= 65137)
                  : (c <= 65139 || (c < 65145
                    ? c == 65143
                    : c <= 65145)))
                : (c <= 65147 || (c < 65296
                  ? (c < 65151
                    ? c == 65149
                    : c <= 65276)
                  : (c <= 65305 || (c < 65343
                    ? (c >= 65313 && c <= 65338)
                    : c <= 65343)))))))))
          : (c <= 65370 || (c < 66513
            ? (c < 65664
              ? (c < 65536
                ? (c < 65482
                  ? (c < 65474
                    ? (c >= 65382 && c <= 65470)
                    : c <= 65479)
                  : (c <= 65487 || (c < 65498
                    ? (c >= 65490 && c <= 65495)
                    : c <= 65500)))
                : (c <= 65547 || (c < 65596
                  ? (c < 65576
                    ? (c >= 65549 && c <= 65574)
                    : c <= 65594)
                  : (c <= 65597 || (c < 65616
                    ? (c >= 65599 && c <= 65613)
                    : c <= 65629)))))
              : (c <= 65786 || (c < 66304
                ? (c < 66176
                  ? (c < 66045
                    ? (c >= 65856 && c <= 65908)
                    : c <= 66045)
                  : (c <= 66204 || (c < 66272
                    ? (c >= 66208 && c <= 66256)
                    : c <= 66272)))
                : (c <= 66335 || (c < 66432
                  ? (c < 66384
                    ? (c >= 66349 && c <= 66378)
                    : c <= 66426)
                  : (c <= 66461 || (c < 66504
                    ? (c >= 66464 && c <= 66499)
                    : c <= 66511)))))))
            : (c <= 66517 || (c < 66979
              ? (c < 66864
                ? (c < 66736
                  ? (c < 66720
                    ? (c >= 66560 && c <= 66717)
                    : c <= 66729)
                  : (c <= 66771 || (c < 66816
                    ? (c >= 66776 && c <= 66811)
                    : c <= 66855)))
                : (c <= 66915 || (c < 66956
                  ? (c < 66940
                    ? (c >= 66928 && c <= 66938)
                    : c <= 66954)
                  : (c <= 66962 || (c < 66967
                    ? (c >= 66964 && c <= 66965)
                    : c <= 66977)))))
              : (c <= 66993 || (c < 67456
                ? (c < 67072
                  ? (c < 67003
                    ? (c >= 66995 && c <= 67001)
                    : c <= 67004)
                  : (c <= 67382 || (c < 67424
                    ? (c >= 67392 && c <= 67413)
                    : c <= 67431)))
                : (c <= 67461 || (c < 67584
                  ? (c < 67506
                    ? (c >= 67463 && c <= 67504)
                    : c <= 67514)
                  : (c <= 67589 || (c < 67594
                    ? c == 67592
                    : c <= 67637)))))))))))
        : (c <= 67640 || (c < 69956
          ? (c < 68448
            ? (c < 68101
              ? (c < 67828
                ? (c < 67680
                  ? (c < 67647
                    ? c == 67644
                    : c <= 67669)
                  : (c <= 67702 || (c < 67808
                    ? (c >= 67712 && c <= 67742)
                    : c <= 67826)))
                : (c <= 67829 || (c < 67968
                  ? (c < 67872
                    ? (c >= 67840 && c <= 67861)
                    : c <= 67897)
                  : (c <= 68023 || (c < 68096
                    ? (c >= 68030 && c <= 68031)
                    : c <= 68099)))))
              : (c <= 68102 || (c < 68192
                ? (c < 68121
                  ? (c < 68117
                    ? (c >= 68108 && c <= 68115)
                    : c <= 68119)
                  : (c <= 68149 || (c < 68159
                    ? (c >= 68152 && c <= 68154)
                    : c <= 68159)))
                : (c <= 68220 || (c < 68297
                  ? (c < 68288
                    ? (c >= 68224 && c <= 68252)
                    : c <= 68295)
                  : (c <= 68326 || (c < 68416
                    ? (c >= 68352 && c <= 68405)
                    : c <= 68437)))))))
            : (c <= 68466 || (c < 69424
              ? (c < 68912
                ? (c < 68736
                  ? (c < 68608
                    ? (c >= 68480 && c <= 68497)
                    : c <= 68680)
                  : (c <= 68786 || (c < 68864
                    ? (c >= 68800 && c <= 68850)
                    : c <= 68903)))
                : (c <= 68921 || (c < 69296
                  ? (c < 69291
                    ? (c >= 69248 && c <= 69289)
                    : c <= 69292)
                  : (c <= 69297 || (c < 69415
                    ? (c >= 69376 && c <= 69404)
                    : c <= 69415)))))
              : (c <= 69456 || (c < 69759
                ? (c < 69600
                  ? (c < 69552
                    ? (c >= 69488 && c <= 69509)
                    : c <= 69572)
                  : (c <= 69622 || (c < 69734
                    ? (c >= 69632 && c <= 69702)
                    : c <= 69749)))
                : (c <= 69818 || (c < 69872
                  ? (c < 69840
                    ? c == 69826
                    : c <= 69864)
                  : (c <= 69881 || (c < 69942
                    ? (c >= 69888 && c <= 69940)
                    : c <= 69951)))))))))
          : (c <= 69959 || (c < 70459
            ? (c < 70282
              ? (c < 70108
                ? (c < 70016
                  ? (c < 70006
                    ? (c >= 69968 && c <= 70003)
                    : c <= 70006)
                  : (c <= 70084 || (c < 70094
                    ? (c >= 70089 && c <= 70092)
                    : c <= 70106)))
                : (c <= 70108 || (c < 70206
                  ? (c < 70163
                    ? (c >= 70144 && c <= 70161)
                    : c <= 70199)
                  : (c <= 70206 || (c < 70280
                    ? (c >= 70272 && c <= 70278)
                    : c <= 70280)))))
              : (c <= 70285 || (c < 70405
                ? (c < 70320
                  ? (c < 70303
                    ? (c >= 70287 && c <= 70301)
                    : c <= 70312)
                  : (c <= 70378 || (c < 70400
                    ? (c >= 70384 && c <= 70393)
                    : c <= 70403)))
                : (c <= 70412 || (c < 70442
                  ? (c < 70419
                    ? (c >= 70415 && c <= 70416)
                    : c <= 70440)
                  : (c <= 70448 || (c < 70453
                    ? (c >= 70450 && c <= 70451)
                    : c <= 70457)))))))
            : (c <= 70468 || (c < 70855
              ? (c < 70502
                ? (c < 70480
                  ? (c < 70475
                    ? (c >= 70471 && c <= 70472)
                    : c <= 70477)
                  : (c <= 70480 || (c < 70493
                    ? c == 70487
                    : c <= 70499)))
                : (c <= 70508 || (c < 70736
                  ? (c < 70656
                    ? (c >= 70512 && c <= 70516)
                    : c <= 70730)
                  : (c <= 70745 || (c < 70784
                    ? (c >= 70750 && c <= 70753)
                    : c <= 70853)))))
              : (c <= 70855 || (c < 71236
                ? (c < 71096
                  ? (c < 71040
                    ? (c >= 70864 && c <= 70873)
                    : c <= 71093)
                  : (c <= 71104 || (c < 71168
                    ? (c >= 71128 && c <= 71133)
                    : c <= 71232)))
                : (c <= 71236 || (c < 71360
                  ? (c < 71296
                    ? (c >= 71248 && c <= 71257)
                    : c <= 71352)
                  : (c <= 71369 || (c >= 71424 && c <= 71450)))))))))))))
      : (c <= 71467 || (c < 119973
        ? (c < 77824
          ? (c < 72760
            ? (c < 72016
              ? (c < 71945
                ? (c < 71680
                  ? (c < 71488
                    ? (c >= 71472 && c <= 71481)
                    : c <= 71494)
                  : (c <= 71738 || (c < 71935
                    ? (c >= 71840 && c <= 71913)
                    : c <= 71942)))
                : (c <= 71945 || (c < 71960
                  ? (c < 71957
                    ? (c >= 71948 && c <= 71955)
                    : c <= 71958)
                  : (c <= 71989 || (c < 71995
                    ? (c >= 71991 && c <= 71992)
                    : c <= 72003)))))
              : (c <= 72025 || (c < 72263
                ? (c < 72154
                  ? (c < 72106
                    ? (c >= 72096 && c <= 72103)
                    : c <= 72151)
                  : (c <= 72161 || (c < 72192
                    ? (c >= 72163 && c <= 72164)
                    : c <= 72254)))
                : (c <= 72263 || (c < 72368
                  ? (c < 72349
                    ? (c >= 72272 && c <= 72345)
                    : c <= 72349)
                  : (c <= 72440 || (c < 72714
                    ? (c >= 72704 && c <= 72712)
                    : c <= 72758)))))))
            : (c <= 72768 || (c < 73056
              ? (c < 72968
                ? (c < 72850
                  ? (c < 72818
                    ? (c >= 72784 && c <= 72793)
                    : c <= 72847)
                  : (c <= 72871 || (c < 72960
                    ? (c >= 72873 && c <= 72886)
                    : c <= 72966)))
                : (c <= 72969 || (c < 73020
                  ? (c < 73018
                    ? (c >= 72971 && c <= 73014)
                    : c <= 73018)
                  : (c <= 73021 || (c < 73040
                    ? (c >= 73023 && c <= 73031)
                    : c <= 73049)))))
              : (c <= 73061 || (c < 73440
                ? (c < 73104
                  ? (c < 73066
                    ? (c >= 73063 && c <= 73064)
                    : c <= 73102)
                  : (c <= 73105 || (c < 73120
                    ? (c >= 73107 && c <= 73112)
                    : c <= 73129)))
                : (c <= 73462 || (c < 74752
                  ? (c < 73728
                    ? c == 73648
                    : c <= 74649)
                  : (c <= 74862 || (c < 77712
                    ? (c >= 74880 && c <= 75075)
                    : c <= 77808)))))))))
          : (c <= 78894 || (c < 110576
            ? (c < 93027
              ? (c < 92864
                ? (c < 92736
                  ? (c < 92160
                    ? (c >= 82944 && c <= 83526)
                    : c <= 92728)
                  : (c <= 92766 || (c < 92784
                    ? (c >= 92768 && c <= 92777)
                    : c <= 92862)))
                : (c <= 92873 || (c < 92928
                  ? (c < 92912
                    ? (c >= 92880 && c <= 92909)
                    : c <= 92916)
                  : (c <= 92982 || (c < 93008
                    ? (c >= 92992 && c <= 92995)
                    : c <= 93017)))))
              : (c <= 93047 || (c < 94176
                ? (c < 93952
                  ? (c < 93760
                    ? (c >= 93053 && c <= 93071)
                    : c <= 93823)
                  : (c <= 94026 || (c < 94095
                    ? (c >= 94031 && c <= 94087)
                    : c <= 94111)))
                : (c <= 94177 || (c < 94208
                  ? (c < 94192
                    ? (c >= 94179 && c <= 94180)
                    : c <= 94193)
                  : (c <= 100343 || (c < 101632
                    ? (c >= 100352 && c <= 101589)
                    : c <= 101640)))))))
            : (c <= 110579 || (c < 118528
              ? (c < 110960
                ? (c < 110592
                  ? (c < 110589
                    ? (c >= 110581 && c <= 110587)
                    : c <= 110590)
                  : (c <= 110882 || (c < 110948
                    ? (c >= 110928 && c <= 110930)
                    : c <= 110951)))
                : (c <= 111355 || (c < 113792
                  ? (c < 113776
                    ? (c >= 113664 && c <= 113770)
                    : c <= 113788)
                  : (c <= 113800 || (c < 113821
                    ? (c >= 113808 && c <= 113817)
                    : c <= 113822)))))
              : (c <= 118573 || (c < 119210
                ? (c < 119149
                  ? (c < 119141
                    ? (c >= 118576 && c <= 118598)
                    : c <= 119145)
                  : (c <= 119154 || (c < 119173
                    ? (c >= 119163 && c <= 119170)
                    : c <= 119179)))
                : (c <= 119213 || (c < 119894
                  ? (c < 119808
                    ? (c >= 119362 && c <= 119364)
                    : c <= 119892)
                  : (c <= 119964 || (c < 119970
                    ? (c >= 119966 && c <= 119967)
                    : c <= 119970)))))))))))
        : (c <= 119974 || (c < 124912
          ? (c < 120746
            ? (c < 120134
              ? (c < 120071
                ? (c < 119995
                  ? (c < 119982
                    ? (c >= 119977 && c <= 119980)
                    : c <= 119993)
                  : (c <= 119995 || (c < 120005
                    ? (c >= 119997 && c <= 120003)
                    : c <= 120069)))
                : (c <= 120074 || (c < 120094
                  ? (c < 120086
                    ? (c >= 120077 && c <= 120084)
                    : c <= 120092)
                  : (c <= 120121 || (c < 120128
                    ? (c >= 120123 && c <= 120126)
                    : c <= 120132)))))
              : (c <= 120134 || (c < 120572
                ? (c < 120488
                  ? (c < 120146
                    ? (c >= 120138 && c <= 120144)
                    : c <= 120485)
                  : (c <= 120512 || (c < 120540
                    ? (c >= 120514 && c <= 120538)
                    : c <= 120570)))
                : (c <= 120596 || (c < 120656
                  ? (c < 120630
                    ? (c >= 120598 && c <= 120628)
                    : c <= 120654)
                  : (c <= 120686 || (c < 120714
                    ? (c >= 120688 && c <= 120712)
                    : c <= 120744)))))))
            : (c <= 120770 || (c < 122907
              ? (c < 121476
                ? (c < 121344
                  ? (c < 120782
                    ? (c >= 120772 && c <= 120779)
                    : c <= 120831)
                  : (c <= 121398 || (c < 121461
                    ? (c >= 121403 && c <= 121452)
                    : c <= 121461)))
                : (c <= 121476 || (c < 122624
                  ? (c < 121505
                    ? (c >= 121499 && c <= 121503)
                    : c <= 121519)
                  : (c <= 122654 || (c < 122888
                    ? (c >= 122880 && c <= 122886)
                    : c <= 122904)))))
              : (c <= 122913 || (c < 123214
                ? (c < 123136
                  ? (c < 122918
                    ? (c >= 122915 && c <= 122916)
                    : c <= 122922)
                  : (c <= 123180 || (c < 123200
                    ? (c >= 123184 && c <= 123197)
                    : c <= 123209)))
                : (c <= 123214 || (c < 124896
                  ? (c < 123584
                    ? (c >= 123536 && c <= 123566)
                    : c <= 123641)
                  : (c <= 124902 || (c < 124909
                    ? (c >= 124904 && c <= 124907)
                    : c <= 124910)))))))))
          : (c <= 124926 || (c < 126557
            ? (c < 126521
              ? (c < 126469
                ? (c < 125184
                  ? (c < 125136
                    ? (c >= 124928 && c <= 125124)
                    : c <= 125142)
                  : (c <= 125259 || (c < 126464
                    ? (c >= 125264 && c <= 125273)
                    : c <= 126467)))
                : (c <= 126495 || (c < 126503
                  ? (c < 126500
                    ? (c >= 126497 && c <= 126498)
                    : c <= 126500)
                  : (c <= 126503 || (c < 126516
                    ? (c >= 126505 && c <= 126514)
                    : c <= 126519)))))
              : (c <= 126521 || (c < 126541
                ? (c < 126535
                  ? (c < 126530
                    ? c == 126523
                    : c <= 126530)
                  : (c <= 126535 || (c < 126539
                    ? c == 126537
                    : c <= 126539)))
                : (c <= 126543 || (c < 126551
                  ? (c < 126548
                    ? (c >= 126545 && c <= 126546)
                    : c <= 126548)
                  : (c <= 126551 || (c < 126555
                    ? c == 126553
                    : c <= 126555)))))))
            : (c <= 126557 || (c < 126629
              ? (c < 126580
                ? (c < 126564
                  ? (c < 126561
                    ? c == 126559
                    : c <= 126562)
                  : (c <= 126564 || (c < 126572
                    ? (c >= 126567 && c <= 126570)
                    : c <= 126578)))
                : (c <= 126583 || (c < 126592
                  ? (c < 126590
                    ? (c >= 126585 && c <= 126588)
                    : c <= 126590)
                  : (c <= 126601 || (c < 126625
                    ? (c >= 126603 && c <= 126619)
                    : c <= 126627)))))
              : (c <= 126633 || (c < 178208
                ? (c < 131072
                  ? (c < 130032
                    ? (c >= 126635 && c <= 126651)
                    : c <= 130041)
                  : (c <= 173791 || (c < 177984
                    ? (c >= 173824 && c <= 177976)
                    : c <= 178205)))
                : (c <= 183969 || (c < 196608
                  ? (c < 194560
                    ? (c >= 183984 && c <= 191456)
                    : c <= 195101)
                  : (c <= 201546 || (c >= 917760 && c <= 917999)))))))))))))))));
}

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(343);
      if (lookahead == '!') ADVANCE(556);
      if (lookahead == '"') ADVANCE(549);
      if (lookahead == '#') ADVANCE(344);
      if (lookahead == ',') ADVANCE(354);
      if (lookahead == '/') ADVANCE(379);
      if (lookahead == '0') ADVANCE(553);
      if (lookahead == '<') ADVANCE(380);
      if (lookahead == '>') ADVANCE(381);
      if (lookahead == '\\') SKIP(336)
      if (lookahead == 'a') ADVANCE(451);
      if (lookahead == 'b') ADVANCE(478);
      if (lookahead == 'd') ADVANCE(479);
      if (lookahead == 'f') ADVANCE(429);
      if (lookahead == 'h') ADVANCE(480);
      if (lookahead == 'i') ADVANCE(436);
      if (lookahead == 'm') ADVANCE(424);
      if (lookahead == 'n') ADVANCE(428);
      if (lookahead == 'o') ADVANCE(526);
      if (lookahead == 'r') ADVANCE(430);
      if (lookahead == 's') ADVANCE(441);
      if (lookahead == 't') ADVANCE(425);
      if (lookahead == 'u') ADVANCE(455);
      if (lookahead == '{') ADVANCE(350);
      if (lookahead == '}') ADVANCE(351);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(0)
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(554);
      if (sym_identifier_character_set_1(lookahead)) ADVANCE(548);
      END_STATE();
    case 1:
      if (lookahead == '\n') SKIP(13)
      END_STATE();
    case 2:
      if (lookahead == '\n') SKIP(13)
      if (lookahead == '\r') SKIP(1)
      END_STATE();
    case 3:
      if (lookahead == '\n') SKIP(14)
      END_STATE();
    case 4:
      if (lookahead == '\n') SKIP(14)
      if (lookahead == '\r') SKIP(3)
      END_STATE();
    case 5:
      if (lookahead == '\n') SKIP(15)
      END_STATE();
    case 6:
      if (lookahead == '\n') SKIP(15)
      if (lookahead == '\r') SKIP(5)
      END_STATE();
    case 7:
      if (lookahead == '\n') SKIP(16)
      END_STATE();
    case 8:
      if (lookahead == '\n') SKIP(16)
      if (lookahead == '\r') SKIP(7)
      END_STATE();
    case 9:
      if (lookahead == '\n') SKIP(17)
      END_STATE();
    case 10:
      if (lookahead == '\n') SKIP(17)
      if (lookahead == '\r') SKIP(9)
      END_STATE();
    case 11:
      if (lookahead == '\n') SKIP(18)
      END_STATE();
    case 12:
      if (lookahead == '\n') SKIP(18)
      if (lookahead == '\r') SKIP(11)
      END_STATE();
    case 13:
      if (lookahead == '#') ADVANCE(344);
      if (lookahead == '\\') SKIP(2)
      if (lookahead == 'a') ADVANCE(452);
      if (lookahead == 'i') ADVANCE(446);
      if (lookahead == 'm') ADVANCE(427);
      if (lookahead == 'n') ADVANCE(504);
      if (lookahead == 'o') ADVANCE(526);
      if (lookahead == 's') ADVANCE(442);
      if (lookahead == 't') ADVANCE(439);
      if (lookahead == 'u') ADVANCE(456);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(13)
      if (sym_identifier_character_set_2(lookahead)) ADVANCE(548);
      END_STATE();
    case 14:
      if (lookahead == '#') ADVANCE(344);
      if (lookahead == '\\') SKIP(4)
      if (lookahead == 'b') ADVANCE(487);
      if (lookahead == 'f') ADVANCE(429);
      if (lookahead == 'r') ADVANCE(458);
      if (lookahead == 's') ADVANCE(528);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(14)
      if (sym_identifier_character_set_3(lookahead)) ADVANCE(548);
      END_STATE();
    case 15:
      if (lookahead == '#') ADVANCE(344);
      if (lookahead == '\\') SKIP(6)
      if (lookahead == 'a') ADVANCE(452);
      if (lookahead == 'i') ADVANCE(447);
      if (lookahead == 'o') ADVANCE(526);
      if (lookahead == 's') ADVANCE(443);
      if (lookahead == 't') ADVANCE(439);
      if (lookahead == 'u') ADVANCE(456);
      if (lookahead == '{') ADVANCE(350);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(15)
      if (sym_identifier_character_set_2(lookahead)) ADVANCE(548);
      END_STATE();
    case 16:
      if (lookahead == '#') ADVANCE(344);
      if (lookahead == '\\') SKIP(8)
      if (lookahead == 'h') ADVANCE(480);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(16)
      if (sym_identifier_character_set_3(lookahead)) ADVANCE(548);
      END_STATE();
    case 17:
      if (lookahead == '#') ADVANCE(344);
      if (lookahead == '\\') SKIP(10)
      if (lookahead == 's') ADVANCE(519);
      if (lookahead == 't') ADVANCE(426);
      if (lookahead == '{') ADVANCE(350);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(17)
      if (sym_identifier_character_set_3(lookahead)) ADVANCE(548);
      END_STATE();
    case 18:
      if (lookahead == '#') ADVANCE(344);
      if (lookahead == '\\') SKIP(12)
      if (lookahead == 'i') ADVANCE(472);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(18)
      if (sym_identifier_character_set_3(lookahead)) ADVANCE(548);
      END_STATE();
    case 19:
      if (lookahead == '-') ADVANCE(53);
      END_STATE();
    case 20:
      if (lookahead == '-') ADVANCE(222);
      END_STATE();
    case 21:
      if (lookahead == 'a') ADVANCE(176);
      END_STATE();
    case 22:
      if (lookahead == 'a') ADVANCE(40);
      END_STATE();
    case 23:
      if (lookahead == 'a') ADVANCE(44);
      END_STATE();
    case 24:
      if (lookahead == 'a') ADVANCE(70);
      END_STATE();
    case 25:
      if (lookahead == 'a') ADVANCE(141);
      END_STATE();
    case 26:
      if (lookahead == 'a') ADVANCE(313);
      END_STATE();
    case 27:
      if (lookahead == 'a') ADVANCE(269);
      END_STATE();
    case 28:
      if (lookahead == 'a') ADVANCE(48);
      END_STATE();
    case 29:
      if (lookahead == 'a') ADVANCE(139);
      END_STATE();
    case 30:
      if (lookahead == 'a') ADVANCE(314);
      END_STATE();
    case 31:
      if (lookahead == 'a') ADVANCE(311);
      END_STATE();
    case 32:
      if (lookahead == 'a') ADVANCE(310);
      END_STATE();
    case 33:
      if (lookahead == 'a') ADVANCE(248);
      END_STATE();
    case 34:
      if (lookahead == 'a') ADVANCE(188);
      END_STATE();
    case 35:
      if (lookahead == 'a') ADVANCE(41);
      END_STATE();
    case 36:
      if (lookahead == 'a') ADVANCE(322);
      END_STATE();
    case 37:
      if (lookahead == 'a') ADVANCE(190);
      END_STATE();
    case 38:
      if (lookahead == 'b') ADVANCE(193);
      END_STATE();
    case 39:
      if (lookahead == 'b') ADVANCE(134);
      END_STATE();
    case 40:
      if (lookahead == 'b') ADVANCE(160);
      END_STATE();
    case 41:
      if (lookahead == 'b') ADVANCE(165);
      END_STATE();
    case 42:
      if (lookahead == 'c') ADVANCE(118);
      END_STATE();
    case 43:
      if (lookahead == 'c') ADVANCE(579);
      END_STATE();
    case 44:
      if (lookahead == 'c') ADVANCE(148);
      END_STATE();
    case 45:
      if (lookahead == 'c') ADVANCE(169);
      END_STATE();
    case 46:
      if (lookahead == 'c') ADVANCE(164);
      if (lookahead == 'e') ADVANCE(272);
      if (lookahead == 'f') ADVANCE(123);
      if (lookahead == 'o') ADVANCE(228);
      if (lookahead == 't') ADVANCE(268);
      END_STATE();
    case 47:
      if (lookahead == 'c') ADVANCE(19);
      END_STATE();
    case 48:
      if (lookahead == 'c') ADVANCE(149);
      END_STATE();
    case 49:
      if (lookahead == 'c') ADVANCE(325);
      END_STATE();
    case 50:
      if (lookahead == 'c') ADVANCE(326);
      END_STATE();
    case 51:
      if (lookahead == 'c') ADVANCE(328);
      END_STATE();
    case 52:
      if (lookahead == 'c') ADVANCE(329);
      END_STATE();
    case 53:
      if (lookahead == 'c') ADVANCE(209);
      if (lookahead == 'n') ADVANCE(219);
      if (lookahead == 's') ADVANCE(312);
      END_STATE();
    case 54:
      if (lookahead == 'c') ADVANCE(119);
      END_STATE();
    case 55:
      if (lookahead == 'c') ADVANCE(121);
      END_STATE();
    case 56:
      if (lookahead == 'c') ADVANCE(166);
      if (lookahead == 'e') ADVANCE(282);
      if (lookahead == 'o') ADVANCE(233);
      END_STATE();
    case 57:
      if (lookahead == 'd') ADVANCE(103);
      END_STATE();
    case 58:
      if (lookahead == 'd') ADVANCE(103);
      if (lookahead == 'r') ADVANCE(201);
      if (lookahead == 's') ADVANCE(331);
      END_STATE();
    case 59:
      if (lookahead == 'd') ADVANCE(352);
      END_STATE();
    case 60:
      if (lookahead == 'd') ADVANCE(580);
      END_STATE();
    case 61:
      if (lookahead == 'd') ADVANCE(360);
      END_STATE();
    case 62:
      if (lookahead == 'd') ADVANCE(365);
      END_STATE();
    case 63:
      if (lookahead == 'd') ADVANCE(597);
      END_STATE();
    case 64:
      if (lookahead == 'd') ADVANCE(375);
      END_STATE();
    case 65:
      if (lookahead == 'd') ADVANCE(357);
      END_STATE();
    case 66:
      if (lookahead == 'd') ADVANCE(363);
      END_STATE();
    case 67:
      if (lookahead == 'd') ADVANCE(87);
      END_STATE();
    case 68:
      if (lookahead == 'd') ADVANCE(99);
      if (lookahead == 'p') ADVANCE(218);
      END_STATE();
    case 69:
      if (lookahead == 'd') ADVANCE(126);
      END_STATE();
    case 70:
      if (lookahead == 'd') ADVANCE(71);
      END_STATE();
    case 71:
      if (lookahead == 'd') ADVANCE(245);
      END_STATE();
    case 72:
      if (lookahead == 'd') ADVANCE(96);
      END_STATE();
    case 73:
      if (lookahead == 'd') ADVANCE(92);
      END_STATE();
    case 74:
      if (lookahead == 'e') ADVANCE(20);
      END_STATE();
    case 75:
      if (lookahead == 'e') ADVANCE(578);
      END_STATE();
    case 76:
      if (lookahead == 'e') ADVANCE(565);
      END_STATE();
    case 77:
      if (lookahead == 'e') ADVANCE(566);
      END_STATE();
    case 78:
      if (lookahead == 'e') ADVANCE(367);
      END_STATE();
    case 79:
      if (lookahead == 'e') ADVANCE(372);
      END_STATE();
    case 80:
      if (lookahead == 'e') ADVANCE(368);
      END_STATE();
    case 81:
      if (lookahead == 'e') ADVANCE(373);
      END_STATE();
    case 82:
      if (lookahead == 'e') ADVANCE(572);
      END_STATE();
    case 83:
      if (lookahead == 'e') ADVANCE(251);
      if (lookahead == 'f') ADVANCE(145);
      END_STATE();
    case 84:
      if (lookahead == 'e') ADVANCE(186);
      END_STATE();
    case 85:
      if (lookahead == 'e') ADVANCE(224);
      END_STATE();
    case 86:
      if (lookahead == 'e') ADVANCE(189);
      END_STATE();
    case 87:
      if (lookahead == 'e') ADVANCE(261);
      END_STATE();
    case 88:
      if (lookahead == 'e') ADVANCE(61);
      if (lookahead == 'i') ADVANCE(177);
      END_STATE();
    case 89:
      if (lookahead == 'e') ADVANCE(62);
      if (lookahead == 'i') ADVANCE(182);
      END_STATE();
    case 90:
      if (lookahead == 'e') ADVANCE(63);
      END_STATE();
    case 91:
      if (lookahead == 'e') ADVANCE(65);
      END_STATE();
    case 92:
      if (lookahead == 'e') ADVANCE(263);
      END_STATE();
    case 93:
      if (lookahead == 'e') ADVANCE(66);
      END_STATE();
    case 94:
      if (lookahead == 'e') ADVANCE(264);
      END_STATE();
    case 95:
      if (lookahead == 'e') ADVANCE(265);
      END_STATE();
    case 96:
      if (lookahead == 'e') ADVANCE(239);
      END_STATE();
    case 97:
      if (lookahead == 'e') ADVANCE(290);
      END_STATE();
    case 98:
      if (lookahead == 'e') ADVANCE(277);
      END_STATE();
    case 99:
      if (lookahead == 'e') ADVANCE(108);
      END_STATE();
    case 100:
      if (lookahead == 'e') ADVANCE(185);
      if (lookahead == 's') ADVANCE(303);
      END_STATE();
    case 101:
      if (lookahead == 'e') ADVANCE(184);
      END_STATE();
    case 102:
      if (lookahead == 'e') ADVANCE(191);
      END_STATE();
    case 103:
      if (lookahead == 'f') ADVANCE(577);
      END_STATE();
    case 104:
      if (lookahead == 'f') ADVANCE(361);
      END_STATE();
    case 105:
      if (lookahead == 'f') ADVANCE(129);
      if (lookahead == 'm') ADVANCE(320);
      if (lookahead == 's') ADVANCE(127);
      END_STATE();
    case 106:
      if (lookahead == 'f') ADVANCE(25);
      END_STATE();
    case 107:
      if (lookahead == 'f') ADVANCE(104);
      END_STATE();
    case 108:
      if (lookahead == 'f') ADVANCE(36);
      END_STATE();
    case 109:
      if (lookahead == 'f') ADVANCE(147);
      if (lookahead == 'm') ADVANCE(323);
      if (lookahead == 's') ADVANCE(144);
      END_STATE();
    case 110:
      if (lookahead == 'g') ADVANCE(358);
      END_STATE();
    case 111:
      if (lookahead == 'g') ADVANCE(356);
      END_STATE();
    case 112:
      if (lookahead == 'g') ADVANCE(364);
      END_STATE();
    case 113:
      if (lookahead == 'g') ADVANCE(362);
      END_STATE();
    case 114:
      if (lookahead == 'g') ADVANCE(155);
      END_STATE();
    case 115:
      if (lookahead == 'g') ADVANCE(159);
      END_STATE();
    case 116:
      if (lookahead == 'h') ADVANCE(591);
      END_STATE();
    case 117:
      if (lookahead == 'h') ADVANCE(27);
      if (lookahead == 't') ADVANCE(250);
      END_STATE();
    case 118:
      if (lookahead == 'h') ADVANCE(208);
      END_STATE();
    case 119:
      if (lookahead == 'h') ADVANCE(210);
      END_STATE();
    case 120:
      if (lookahead == 'h') ADVANCE(91);
      END_STATE();
    case 121:
      if (lookahead == 'h') ADVANCE(212);
      END_STATE();
    case 122:
      if (lookahead == 'h') ADVANCE(93);
      END_STATE();
    case 123:
      if (lookahead == 'i') ADVANCE(171);
      END_STATE();
    case 124:
      if (lookahead == 'i') ADVANCE(333);
      END_STATE();
    case 125:
      if (lookahead == 'i') ADVANCE(170);
      END_STATE();
    case 126:
      if (lookahead == 'i') ADVANCE(107);
      END_STATE();
    case 127:
      if (lookahead == 'i') ADVANCE(172);
      END_STATE();
    case 128:
      if (lookahead == 'i') ADVANCE(60);
      END_STATE();
    case 129:
      if (lookahead == 'i') ADVANCE(253);
      END_STATE();
    case 130:
      if (lookahead == 'i') ADVANCE(45);
      if (lookahead == 'r') ADVANCE(278);
      END_STATE();
    case 131:
      if (lookahead == 'i') ADVANCE(49);
      END_STATE();
    case 132:
      if (lookahead == 'i') ADVANCE(50);
      END_STATE();
    case 133:
      if (lookahead == 'i') ADVANCE(180);
      END_STATE();
    case 134:
      if (lookahead == 'i') ADVANCE(173);
      END_STATE();
    case 135:
      if (lookahead == 'i') ADVANCE(52);
      END_STATE();
    case 136:
      if (lookahead == 'i') ADVANCE(270);
      END_STATE();
    case 137:
      if (lookahead == 'i') ADVANCE(183);
      END_STATE();
    case 138:
      if (lookahead == 'i') ADVANCE(213);
      END_STATE();
    case 139:
      if (lookahead == 'i') ADVANCE(289);
      END_STATE();
    case 140:
      if (lookahead == 'i') ADVANCE(231);
      END_STATE();
    case 141:
      if (lookahead == 'i') ADVANCE(157);
      END_STATE();
    case 142:
      if (lookahead == 'i') ADVANCE(281);
      END_STATE();
    case 143:
      if (lookahead == 'i') ADVANCE(94);
      END_STATE();
    case 144:
      if (lookahead == 'i') ADVANCE(192);
      END_STATE();
    case 145:
      if (lookahead == 'i') ADVANCE(254);
      END_STATE();
    case 146:
      if (lookahead == 'i') ADVANCE(232);
      END_STATE();
    case 147:
      if (lookahead == 'i') ADVANCE(255);
      END_STATE();
    case 148:
      if (lookahead == 'k') ADVANCE(376);
      END_STATE();
    case 149:
      if (lookahead == 'k') ADVANCE(592);
      END_STATE();
    case 150:
      if (lookahead == 'l') ADVANCE(575);
      END_STATE();
    case 151:
      if (lookahead == 'l') ADVANCE(26);
      END_STATE();
    case 152:
      if (lookahead == 'l') ADVANCE(327);
      END_STATE();
    case 153:
      if (lookahead == 'l') ADVANCE(131);
      END_STATE();
    case 154:
      if (lookahead == 'l') ADVANCE(302);
      END_STATE();
    case 155:
      if (lookahead == 'l') ADVANCE(78);
      END_STATE();
    case 156:
      if (lookahead == 'l') ADVANCE(132);
      END_STATE();
    case 157:
      if (lookahead == 'l') ADVANCE(90);
      END_STATE();
    case 158:
      if (lookahead == 'l') ADVANCE(135);
      END_STATE();
    case 159:
      if (lookahead == 'l') ADVANCE(79);
      END_STATE();
    case 160:
      if (lookahead == 'l') ADVANCE(136);
      END_STATE();
    case 161:
      if (lookahead == 'l') ADVANCE(80);
      END_STATE();
    case 162:
      if (lookahead == 'l') ADVANCE(81);
      END_STATE();
    case 163:
      if (lookahead == 'l') ADVANCE(309);
      END_STATE();
    case 164:
      if (lookahead == 'l') ADVANCE(205);
      END_STATE();
    case 165:
      if (lookahead == 'l') ADVANCE(142);
      END_STATE();
    case 166:
      if (lookahead == 'l') ADVANCE(216);
      END_STATE();
    case 167:
      if (lookahead == 'l') ADVANCE(318);
      END_STATE();
    case 168:
      if (lookahead == 'm') ADVANCE(271);
      if (lookahead == 's') ADVANCE(234);
      END_STATE();
    case 169:
      if (lookahead == 'm') ADVANCE(220);
      END_STATE();
    case 170:
      if (lookahead == 'm') ADVANCE(124);
      END_STATE();
    case 171:
      if (lookahead == 'n') ADVANCE(324);
      if (lookahead == 'r') ADVANCE(274);
      END_STATE();
    case 172:
      if (lookahead == 'n') ADVANCE(114);
      END_STATE();
    case 173:
      if (lookahead == 'n') ADVANCE(587);
      END_STATE();
    case 174:
      if (lookahead == 'n') ADVANCE(571);
      END_STATE();
    case 175:
      if (lookahead == 'n') ADVANCE(589);
      END_STATE();
    case 176:
      if (lookahead == 'n') ADVANCE(42);
      END_STATE();
    case 177:
      if (lookahead == 'n') ADVANCE(110);
      END_STATE();
    case 178:
      if (lookahead == 'n') ADVANCE(43);
      END_STATE();
    case 179:
      if (lookahead == 'n') ADVANCE(59);
      END_STATE();
    case 180:
      if (lookahead == 'n') ADVANCE(111);
      END_STATE();
    case 181:
      if (lookahead == 'n') ADVANCE(195);
      END_STATE();
    case 182:
      if (lookahead == 'n') ADVANCE(112);
      END_STATE();
    case 183:
      if (lookahead == 'n') ADVANCE(113);
      END_STATE();
    case 184:
      if (lookahead == 'n') ADVANCE(51);
      END_STATE();
    case 185:
      if (lookahead == 'n') ADVANCE(64);
      END_STATE();
    case 186:
      if (lookahead == 'n') ADVANCE(307);
      END_STATE();
    case 187:
      if (lookahead == 'n') ADVANCE(174);
      END_STATE();
    case 188:
      if (lookahead == 'n') ADVANCE(54);
      END_STATE();
    case 189:
      if (lookahead == 'n') ADVANCE(133);
      END_STATE();
    case 190:
      if (lookahead == 'n') ADVANCE(55);
      END_STATE();
    case 191:
      if (lookahead == 'n') ADVANCE(137);
      END_STATE();
    case 192:
      if (lookahead == 'n') ADVANCE(115);
      END_STATE();
    case 193:
      if (lookahead == 'o') ADVANCE(319);
      END_STATE();
    case 194:
      if (lookahead == 'o') ADVANCE(563);
      END_STATE();
    case 195:
      if (lookahead == 'o') ADVANCE(67);
      END_STATE();
    case 196:
      if (lookahead == 'o') ADVANCE(582);
      END_STATE();
    case 197:
      if (lookahead == 'o') ADVANCE(588);
      END_STATE();
    case 198:
      if (lookahead == 'o') ADVANCE(560);
      END_STATE();
    case 199:
      if (lookahead == 'o') ADVANCE(562);
      END_STATE();
    case 200:
      if (lookahead == 'o') ADVANCE(39);
      END_STATE();
    case 201:
      if (lookahead == 'o') ADVANCE(321);
      END_STATE();
    case 202:
      if (lookahead == 'o') ADVANCE(226);
      END_STATE();
    case 203:
      if (lookahead == 'o') ADVANCE(153);
      END_STATE();
    case 204:
      if (lookahead == 'o') ADVANCE(259);
      END_STATE();
    case 205:
      if (lookahead == 'o') ADVANCE(260);
      END_STATE();
    case 206:
      if (lookahead == 'o') ADVANCE(246);
      END_STATE();
    case 207:
      if (lookahead == 'o') ADVANCE(235);
      END_STATE();
    case 208:
      if (lookahead == 'o') ADVANCE(236);
      END_STATE();
    case 209:
      if (lookahead == 'o') ADVANCE(187);
      END_STATE();
    case 210:
      if (lookahead == 'o') ADVANCE(237);
      END_STATE();
    case 211:
      if (lookahead == 'o') ADVANCE(249);
      END_STATE();
    case 212:
      if (lookahead == 'o') ADVANCE(238);
      END_STATE();
    case 213:
      if (lookahead == 'o') ADVANCE(175);
      END_STATE();
    case 214:
      if (lookahead == 'o') ADVANCE(227);
      END_STATE();
    case 215:
      if (lookahead == 'o') ADVANCE(156);
      END_STATE();
    case 216:
      if (lookahead == 'o') ADVANCE(280);
      END_STATE();
    case 217:
      if (lookahead == 'o') ADVANCE(247);
      END_STATE();
    case 218:
      if (lookahead == 'o') ADVANCE(158);
      END_STATE();
    case 219:
      if (lookahead == 'o') ADVANCE(73);
      END_STATE();
    case 220:
      if (lookahead == 'p') ADVANCE(584);
      END_STATE();
    case 221:
      if (lookahead == 'p') ADVANCE(203);
      END_STATE();
    case 222:
      if (lookahead == 'p') ADVANCE(206);
      END_STATE();
    case 223:
      if (lookahead == 'p') ADVANCE(76);
      END_STATE();
    case 224:
      if (lookahead == 'p') ADVANCE(152);
      END_STATE();
    case 225:
      if (lookahead == 'p') ADVANCE(77);
      END_STATE();
    case 226:
      if (lookahead == 'p') ADVANCE(301);
      END_STATE();
    case 227:
      if (lookahead == 'p') ADVANCE(308);
      END_STATE();
    case 228:
      if (lookahead == 'p') ADVANCE(86);
      END_STATE();
    case 229:
      if (lookahead == 'p') ADVANCE(215);
      END_STATE();
    case 230:
      if (lookahead == 'p') ADVANCE(217);
      END_STATE();
    case 231:
      if (lookahead == 'p') ADVANCE(161);
      END_STATE();
    case 232:
      if (lookahead == 'p') ADVANCE(162);
      END_STATE();
    case 233:
      if (lookahead == 'p') ADVANCE(102);
      END_STATE();
    case 234:
      if (lookahead == 'r') ADVANCE(47);
      END_STATE();
    case 235:
      if (lookahead == 'r') ADVANCE(370);
      END_STATE();
    case 236:
      if (lookahead == 'r') ADVANCE(576);
      END_STATE();
    case 237:
      if (lookahead == 'r') ADVANCE(581);
      END_STATE();
    case 238:
      if (lookahead == 'r') ADVANCE(558);
      END_STATE();
    case 239:
      if (lookahead == 'r') ADVANCE(583);
      END_STATE();
    case 240:
      if (lookahead == 'r') ADVANCE(23);
      END_STATE();
    case 241:
      if (lookahead == 'r') ADVANCE(85);
      if (lookahead == 't') ADVANCE(199);
      END_STATE();
    case 242:
      if (lookahead == 'r') ADVANCE(200);
      END_STATE();
    case 243:
      if (lookahead == 'r') ADVANCE(143);
      END_STATE();
    case 244:
      if (lookahead == 'r') ADVANCE(207);
      END_STATE();
    case 245:
      if (lookahead == 'r') ADVANCE(98);
      END_STATE();
    case 246:
      if (lookahead == 'r') ADVANCE(305);
      END_STATE();
    case 247:
      if (lookahead == 'r') ADVANCE(288);
      END_STATE();
    case 248:
      if (lookahead == 'r') ADVANCE(291);
      END_STATE();
    case 249:
      if (lookahead == 'r') ADVANCE(72);
      END_STATE();
    case 250:
      if (lookahead == 'r') ADVANCE(28);
      END_STATE();
    case 251:
      if (lookahead == 'r') ADVANCE(244);
      END_STATE();
    case 252:
      if (lookahead == 'r') ADVANCE(31);
      END_STATE();
    case 253:
      if (lookahead == 'r') ADVANCE(275);
      END_STATE();
    case 254:
      if (lookahead == 'r') ADVANCE(276);
      END_STATE();
    case 255:
      if (lookahead == 'r') ADVANCE(279);
      END_STATE();
    case 256:
      if (lookahead == 's') ADVANCE(331);
      END_STATE();
    case 257:
      if (lookahead == 's') ADVANCE(234);
      END_STATE();
    case 258:
      if (lookahead == 's') ADVANCE(570);
      END_STATE();
    case 259:
      if (lookahead == 's') ADVANCE(590);
      END_STATE();
    case 260:
      if (lookahead == 's') ADVANCE(88);
      END_STATE();
    case 261:
      if (lookahead == 's') ADVANCE(377);
      END_STATE();
    case 262:
      if (lookahead == 's') ADVANCE(557);
      END_STATE();
    case 263:
      if (lookahead == 's') ADVANCE(573);
      END_STATE();
    case 264:
      if (lookahead == 's') ADVANCE(378);
      END_STATE();
    case 265:
      if (lookahead == 's') ADVANCE(574);
      END_STATE();
    case 266:
      if (lookahead == 's') ADVANCE(593);
      END_STATE();
    case 267:
      if (lookahead == 's') ADVANCE(596);
      END_STATE();
    case 268:
      if (lookahead == 's') ADVANCE(69);
      END_STATE();
    case 269:
      if (lookahead == 's') ADVANCE(116);
      END_STATE();
    case 270:
      if (lookahead == 's') ADVANCE(120);
      END_STATE();
    case 271:
      if (lookahead == 's') ADVANCE(258);
      END_STATE();
    case 272:
      if (lookahead == 's') ADVANCE(299);
      END_STATE();
    case 273:
      if (lookahead == 's') ADVANCE(97);
      END_STATE();
    case 274:
      if (lookahead == 's') ADVANCE(283);
      END_STATE();
    case 275:
      if (lookahead == 's') ADVANCE(284);
      END_STATE();
    case 276:
      if (lookahead == 's') ADVANCE(285);
      END_STATE();
    case 277:
      if (lookahead == 's') ADVANCE(267);
      END_STATE();
    case 278:
      if (lookahead == 's') ADVANCE(286);
      END_STATE();
    case 279:
      if (lookahead == 's') ADVANCE(287);
      END_STATE();
    case 280:
      if (lookahead == 's') ADVANCE(89);
      END_STATE();
    case 281:
      if (lookahead == 's') ADVANCE(122);
      END_STATE();
    case 282:
      if (lookahead == 's') ADVANCE(317);
      END_STATE();
    case 283:
      if (lookahead == 't') ADVANCE(355);
      END_STATE();
    case 284:
      if (lookahead == 't') ADVANCE(366);
      END_STATE();
    case 285:
      if (lookahead == 't') ADVANCE(369);
      END_STATE();
    case 286:
      if (lookahead == 't') ADVANCE(586);
      END_STATE();
    case 287:
      if (lookahead == 't') ADVANCE(371);
      END_STATE();
    case 288:
      if (lookahead == 't') ADVANCE(595);
      END_STATE();
    case 289:
      if (lookahead == 't') ADVANCE(359);
      END_STATE();
    case 290:
      if (lookahead == 't') ADVANCE(567);
      END_STATE();
    case 291:
      if (lookahead == 't') ADVANCE(374);
      END_STATE();
    case 292:
      if (lookahead == 't') ADVANCE(194);
      END_STATE();
    case 293:
      if (lookahead == 't') ADVANCE(330);
      END_STATE();
    case 294:
      if (lookahead == 't') ADVANCE(240);
      END_STATE();
    case 295:
      if (lookahead == 't') ADVANCE(204);
      END_STATE();
    case 296:
      if (lookahead == 't') ADVANCE(75);
      END_STATE();
    case 297:
      if (lookahead == 't') ADVANCE(150);
      END_STATE();
    case 298:
      if (lookahead == 't') ADVANCE(297);
      END_STATE();
    case 299:
      if (lookahead == 't') ADVANCE(22);
      END_STATE();
    case 300:
      if (lookahead == 't') ADVANCE(196);
      END_STATE();
    case 301:
      if (lookahead == 't') ADVANCE(262);
      END_STATE();
    case 302:
      if (lookahead == 't') ADVANCE(140);
      END_STATE();
    case 303:
      if (lookahead == 't') ADVANCE(33);
      END_STATE();
    case 304:
      if (lookahead == 't') ADVANCE(197);
      END_STATE();
    case 305:
      if (lookahead == 't') ADVANCE(273);
      END_STATE();
    case 306:
      if (lookahead == 't') ADVANCE(198);
      END_STATE();
    case 307:
      if (lookahead == 't') ADVANCE(243);
      END_STATE();
    case 308:
      if (lookahead == 't') ADVANCE(125);
      END_STATE();
    case 309:
      if (lookahead == 't') ADVANCE(266);
      END_STATE();
    case 310:
      if (lookahead == 't') ADVANCE(138);
      END_STATE();
    case 311:
      if (lookahead == 't') ADVANCE(82);
      END_STATE();
    case 312:
      if (lookahead == 't') ADVANCE(30);
      END_STATE();
    case 313:
      if (lookahead == 't') ADVANCE(101);
      END_STATE();
    case 314:
      if (lookahead == 't') ADVANCE(95);
      END_STATE();
    case 315:
      if (lookahead == 't') ADVANCE(332);
      END_STATE();
    case 316:
      if (lookahead == 't') ADVANCE(250);
      END_STATE();
    case 317:
      if (lookahead == 't') ADVANCE(35);
      END_STATE();
    case 318:
      if (lookahead == 't') ADVANCE(146);
      END_STATE();
    case 319:
      if (lookahead == 'u') ADVANCE(179);
      END_STATE();
    case 320:
      if (lookahead == 'u') ADVANCE(154);
      END_STATE();
    case 321:
      if (lookahead == 'u') ADVANCE(296);
      END_STATE();
    case 322:
      if (lookahead == 'u') ADVANCE(163);
      END_STATE();
    case 323:
      if (lookahead == 'u') ADVANCE(167);
      END_STATE();
    case 324:
      if (lookahead == 'w') ADVANCE(29);
      END_STATE();
    case 325:
      if (lookahead == 'y') ADVANCE(564);
      END_STATE();
    case 326:
      if (lookahead == 'y') ADVANCE(559);
      END_STATE();
    case 327:
      if (lookahead == 'y') ADVANCE(561);
      END_STATE();
    case 328:
      if (lookahead == 'y') ADVANCE(353);
      END_STATE();
    case 329:
      if (lookahead == 'y') ADVANCE(594);
      END_STATE();
    case 330:
      if (lookahead == 'y') ADVANCE(223);
      END_STATE();
    case 331:
      if (lookahead == 'y') ADVANCE(178);
      END_STATE();
    case 332:
      if (lookahead == 'y') ADVANCE(225);
      END_STATE();
    case 333:
      if (lookahead == 'z') ADVANCE(32);
      END_STATE();
    case 334:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(555);
      END_STATE();
    case 335:
      if (eof) ADVANCE(343);
      if (lookahead == '\n') SKIP(0)
      END_STATE();
    case 336:
      if (eof) ADVANCE(343);
      if (lookahead == '\n') SKIP(0)
      if (lookahead == '\r') SKIP(335)
      END_STATE();
    case 337:
      if (eof) ADVANCE(343);
      if (lookahead == '\n') SKIP(341)
      END_STATE();
    case 338:
      if (eof) ADVANCE(343);
      if (lookahead == '\n') SKIP(341)
      if (lookahead == '\r') SKIP(337)
      END_STATE();
    case 339:
      if (eof) ADVANCE(343);
      if (lookahead == '\n') SKIP(342)
      END_STATE();
    case 340:
      if (eof) ADVANCE(343);
      if (lookahead == '\n') SKIP(342)
      if (lookahead == '\r') SKIP(339)
      END_STATE();
    case 341:
      if (eof) ADVANCE(343);
      if (lookahead == '!') ADVANCE(556);
      if (lookahead == '#') ADVANCE(344);
      if (lookahead == ',') ADVANCE(354);
      if (lookahead == '\\') SKIP(338)
      if (lookahead == '{') ADVANCE(350);
      if (lookahead == '}') ADVANCE(351);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(341)
      if (sym_identifier_character_set_3(lookahead)) ADVANCE(548);
      END_STATE();
    case 342:
      if (eof) ADVANCE(343);
      if (lookahead == '#') ADVANCE(344);
      if (lookahead == '\\') SKIP(340)
      if (lookahead == 'n') ADVANCE(505);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(342)
      if (sym_identifier_character_set_3(lookahead)) ADVANCE(548);
      END_STATE();
    case 343:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 344:
      ACCEPT_TOKEN(anon_sym_POUND);
      END_STATE();
    case 345:
      ACCEPT_TOKEN(anon_sym_POUND);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '"') ADVANCE(552);
      END_STATE();
    case 346:
      ACCEPT_TOKEN(anon_sym_POUND);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(349);
      END_STATE();
    case 347:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == '\r') ADVANCE(349);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(349);
      END_STATE();
    case 348:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == '#') ADVANCE(346);
      if (lookahead == '\\') ADVANCE(347);
      if (lookahead == '\t' ||
          (11 <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(348);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(349);
      END_STATE();
    case 349:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(349);
      END_STATE();
    case 350:
      ACCEPT_TOKEN(anon_sym_LBRACE);
      END_STATE();
    case 351:
      ACCEPT_TOKEN(anon_sym_RBRACE);
      END_STATE();
    case 352:
      ACCEPT_TOKEN(anon_sym_if_DASHbound);
      END_STATE();
    case 353:
      ACCEPT_TOKEN(anon_sym_high_DASHlatency);
      END_STATE();
    case 354:
      ACCEPT_TOKEN(anon_sym_COMMA);
      END_STATE();
    case 355:
      ACCEPT_TOKEN(anon_sym_tcp_DOTfirst);
      END_STATE();
    case 356:
      ACCEPT_TOKEN(anon_sym_tcp_DOTopening);
      END_STATE();
    case 357:
      ACCEPT_TOKEN(anon_sym_tcp_DOTestablished);
      END_STATE();
    case 358:
      ACCEPT_TOKEN(anon_sym_tcp_DOTclosing);
      END_STATE();
    case 359:
      ACCEPT_TOKEN(anon_sym_tcp_DOTfinwait);
      END_STATE();
    case 360:
      ACCEPT_TOKEN(anon_sym_tcp_DOTclosed);
      END_STATE();
    case 361:
      ACCEPT_TOKEN(anon_sym_tcp_DOTtsdiff);
      END_STATE();
    case 362:
      ACCEPT_TOKEN(anon_sym_sctp_DOTopening);
      END_STATE();
    case 363:
      ACCEPT_TOKEN(anon_sym_sctp_DOTestablished);
      END_STATE();
    case 364:
      ACCEPT_TOKEN(anon_sym_sctp_DOTclosing);
      END_STATE();
    case 365:
      ACCEPT_TOKEN(anon_sym_sctp_DOTclosed);
      END_STATE();
    case 366:
      ACCEPT_TOKEN(anon_sym_udp_DOTfirst);
      END_STATE();
    case 367:
      ACCEPT_TOKEN(anon_sym_udp_DOTsingle);
      END_STATE();
    case 368:
      ACCEPT_TOKEN(anon_sym_udp_DOTmultiple);
      END_STATE();
    case 369:
      ACCEPT_TOKEN(anon_sym_icmp_DOTfirst);
      END_STATE();
    case 370:
      ACCEPT_TOKEN(anon_sym_icmp_DOTerror);
      END_STATE();
    case 371:
      ACCEPT_TOKEN(anon_sym_other_DOTfirst);
      END_STATE();
    case 372:
      ACCEPT_TOKEN(anon_sym_other_DOTsingle);
      END_STATE();
    case 373:
      ACCEPT_TOKEN(anon_sym_other_DOTmultiple);
      END_STATE();
    case 374:
      ACCEPT_TOKEN(anon_sym_adaptive_DOTstart);
      END_STATE();
    case 375:
      ACCEPT_TOKEN(anon_sym_adaptive_DOTend);
      END_STATE();
    case 376:
      ACCEPT_TOKEN(anon_sym_src_DOTtrack);
      END_STATE();
    case 377:
      ACCEPT_TOKEN(anon_sym_src_DASHnodes);
      END_STATE();
    case 378:
      ACCEPT_TOKEN(anon_sym_table_DASHentries);
      END_STATE();
    case 379:
      ACCEPT_TOKEN(anon_sym_SLASH);
      END_STATE();
    case 380:
      ACCEPT_TOKEN(anon_sym_LT);
      END_STATE();
    case 381:
      ACCEPT_TOKEN(anon_sym_GT);
      END_STATE();
    case 382:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '-') ADVANCE(38);
      if (sym_identifier_character_set_4(lookahead)) ADVANCE(548);
      END_STATE();
    case 383:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '-') ADVANCE(58);
      if (sym_identifier_character_set_4(lookahead)) ADVANCE(548);
      END_STATE();
    case 384:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '-') ADVANCE(292);
      if (sym_identifier_character_set_4(lookahead)) ADVANCE(548);
      END_STATE();
    case 385:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '-') ADVANCE(74);
      if (sym_identifier_character_set_4(lookahead)) ADVANCE(548);
      END_STATE();
    case 386:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '-') ADVANCE(21);
      if (sym_identifier_character_set_4(lookahead)) ADVANCE(548);
      END_STATE();
    case 387:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '-') ADVANCE(181);
      if (lookahead == '.') ADVANCE(294);
      if (sym_identifier_character_set_4(lookahead)) ADVANCE(548);
      END_STATE();
    case 388:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '-') ADVANCE(181);
      if (sym_identifier_character_set_4(lookahead)) ADVANCE(548);
      END_STATE();
    case 389:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '-') ADVANCE(221);
      if (sym_identifier_character_set_4(lookahead)) ADVANCE(548);
      END_STATE();
    case 390:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '-') ADVANCE(151);
      if (sym_identifier_character_set_4(lookahead)) ADVANCE(548);
      END_STATE();
    case 391:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '-') ADVANCE(68);
      if (sym_identifier_character_set_4(lookahead)) ADVANCE(548);
      END_STATE();
    case 392:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '-') ADVANCE(241);
      if (sym_identifier_character_set_4(lookahead)) ADVANCE(548);
      END_STATE();
    case 393:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '-') ADVANCE(130);
      if (sym_identifier_character_set_4(lookahead)) ADVANCE(548);
      END_STATE();
    case 394:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '-') ADVANCE(117);
      if (sym_identifier_character_set_4(lookahead)) ADVANCE(548);
      END_STATE();
    case 395:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '-') ADVANCE(298);
      if (sym_identifier_character_set_4(lookahead)) ADVANCE(548);
      END_STATE();
    case 396:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '-') ADVANCE(84);
      if (sym_identifier_character_set_4(lookahead)) ADVANCE(548);
      END_STATE();
    case 397:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '-') ADVANCE(106);
      if (sym_identifier_character_set_4(lookahead)) ADVANCE(548);
      END_STATE();
    case 398:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '-') ADVANCE(293);
      if (lookahead == '.') ADVANCE(83);
      if (lookahead == '6') ADVANCE(414);
      if (sym_identifier_character_set_4(lookahead)) ADVANCE(548);
      END_STATE();
    case 399:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '-') ADVANCE(242);
      if (sym_identifier_character_set_4(lookahead)) ADVANCE(548);
      END_STATE();
    case 400:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '-') ADVANCE(128);
      if (sym_identifier_character_set_4(lookahead)) ADVANCE(548);
      END_STATE();
    case 401:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '-') ADVANCE(202);
      if (sym_identifier_character_set_4(lookahead)) ADVANCE(548);
      END_STATE();
    case 402:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '-') ADVANCE(24);
      if (sym_identifier_character_set_4(lookahead)) ADVANCE(548);
      END_STATE();
    case 403:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '-') ADVANCE(57);
      if (sym_identifier_character_set_4(lookahead)) ADVANCE(548);
      END_STATE();
    case 404:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '-') ADVANCE(211);
      if (sym_identifier_character_set_4(lookahead)) ADVANCE(548);
      END_STATE();
    case 405:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '-') ADVANCE(256);
      if (sym_identifier_character_set_4(lookahead)) ADVANCE(548);
      END_STATE();
    case 406:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '-') ADVANCE(295);
      if (sym_identifier_character_set_4(lookahead)) ADVANCE(548);
      END_STATE();
    case 407:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '-') ADVANCE(214);
      if (sym_identifier_character_set_4(lookahead)) ADVANCE(548);
      END_STATE();
    case 408:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '-') ADVANCE(300);
      if (sym_identifier_character_set_4(lookahead)) ADVANCE(548);
      END_STATE();
    case 409:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '-') ADVANCE(230);
      if (sym_identifier_character_set_4(lookahead)) ADVANCE(548);
      END_STATE();
    case 410:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '-') ADVANCE(304);
      if (sym_identifier_character_set_4(lookahead)) ADVANCE(548);
      END_STATE();
    case 411:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '-') ADVANCE(306);
      if (sym_identifier_character_set_4(lookahead)) ADVANCE(548);
      END_STATE();
    case 412:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '-') ADVANCE(229);
      if (sym_identifier_character_set_4(lookahead)) ADVANCE(548);
      END_STATE();
    case 413:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '-') ADVANCE(316);
      if (sym_identifier_character_set_4(lookahead)) ADVANCE(548);
      END_STATE();
    case 414:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '-') ADVANCE(315);
      if (sym_identifier_character_set_4(lookahead)) ADVANCE(548);
      END_STATE();
    case 415:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '-') ADVANCE(34);
      if (sym_identifier_character_set_4(lookahead)) ADVANCE(548);
      END_STATE();
    case 416:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '-') ADVANCE(37);
      if (sym_identifier_character_set_4(lookahead)) ADVANCE(548);
      END_STATE();
    case 417:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '.') ADVANCE(46);
      if (sym_identifier_character_set_4(lookahead)) ADVANCE(548);
      END_STATE();
    case 418:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '.') ADVANCE(105);
      if (sym_identifier_character_set_4(lookahead)) ADVANCE(548);
      END_STATE();
    case 419:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '.') ADVANCE(83);
      if (sym_identifier_character_set_4(lookahead)) ADVANCE(548);
      END_STATE();
    case 420:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '.') ADVANCE(56);
      if (sym_identifier_character_set_4(lookahead)) ADVANCE(548);
      END_STATE();
    case 421:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '.') ADVANCE(100);
      if (sym_identifier_character_set_4(lookahead)) ADVANCE(548);
      END_STATE();
    case 422:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '.') ADVANCE(294);
      if (sym_identifier_character_set_4(lookahead)) ADVANCE(548);
      END_STATE();
    case 423:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '.') ADVANCE(109);
      if (sym_identifier_character_set_4(lookahead)) ADVANCE(548);
      END_STATE();
    case 424:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'a') ADVANCE(513);
      if (lookahead == 'i') ADVANCE(499);
      if (sym_identifier_character_set_5(lookahead)) ADVANCE(548);
      END_STATE();
    case 425:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'a') ADVANCE(435);
      if (lookahead == 'c') ADVANCE(506);
      if (sym_identifier_character_set_5(lookahead)) ADVANCE(548);
      END_STATE();
    case 426:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'a') ADVANCE(435);
      if (sym_identifier_character_set_5(lookahead)) ADVANCE(548);
      END_STATE();
    case 427:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'a') ADVANCE(545);
      if (sym_identifier_character_set_5(lookahead)) ADVANCE(548);
      END_STATE();
    case 428:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'a') ADVANCE(530);
      if (lookahead == 'o') ADVANCE(383);
      if (sym_identifier_character_set_5(lookahead)) ADVANCE(548);
      END_STATE();
    case 429:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'a') ADVANCE(482);
      if (sym_identifier_character_set_5(lookahead)) ADVANCE(548);
      END_STATE();
    case 430:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'a') ADVANCE(496);
      if (lookahead == 'd') ADVANCE(523);
      if (lookahead == 'e') ADVANCE(510);
      if (lookahead == 'o') ADVANCE(537);
      if (sym_identifier_character_set_5(lookahead)) ADVANCE(548);
      END_STATE();
    case 431:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'a') ADVANCE(527);
      if (lookahead == 'i') ADVANCE(440);
      if (sym_identifier_character_set_5(lookahead)) ADVANCE(548);
      END_STATE();
    case 432:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'a') ADVANCE(514);
      if (sym_identifier_character_set_5(lookahead)) ADVANCE(548);
      END_STATE();
    case 433:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'a') ADVANCE(535);
      if (sym_identifier_character_set_5(lookahead)) ADVANCE(548);
      END_STATE();
    case 434:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'a') ADVANCE(536);
      if (sym_identifier_character_set_5(lookahead)) ADVANCE(548);
      END_STATE();
    case 435:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'b') ADVANCE(492);
      if (sym_identifier_character_set_4(lookahead)) ADVANCE(548);
      END_STATE();
    case 436:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'c') ADVANCE(493);
      if (lookahead == 'f') ADVANCE(382);
      if (sym_identifier_character_set_4(lookahead)) ADVANCE(548);
      END_STATE();
    case 437:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'c') ADVANCE(387);
      if (sym_identifier_character_set_4(lookahead)) ADVANCE(548);
      END_STATE();
    case 438:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'c') ADVANCE(486);
      if (sym_identifier_character_set_4(lookahead)) ADVANCE(548);
      END_STATE();
    case 439:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'c') ADVANCE(506);
      if (sym_identifier_character_set_4(lookahead)) ADVANCE(548);
      END_STATE();
    case 440:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'c') ADVANCE(485);
      if (sym_identifier_character_set_4(lookahead)) ADVANCE(548);
      END_STATE();
    case 441:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'c') ADVANCE(531);
      if (lookahead == 'e') ADVANCE(533);
      if (lookahead == 'o') ADVANCE(538);
      if (lookahead == 'r') ADVANCE(437);
      if (lookahead == 't') ADVANCE(431);
      if (sym_identifier_character_set_4(lookahead)) ADVANCE(548);
      END_STATE();
    case 442:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'c') ADVANCE(531);
      if (lookahead == 'o') ADVANCE(541);
      if (lookahead == 'r') ADVANCE(444);
      if (sym_identifier_character_set_4(lookahead)) ADVANCE(548);
      END_STATE();
    case 443:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'c') ADVANCE(531);
      if (lookahead == 'r') ADVANCE(444);
      if (sym_identifier_character_set_4(lookahead)) ADVANCE(548);
      END_STATE();
    case 444:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'c') ADVANCE(422);
      if (sym_identifier_character_set_4(lookahead)) ADVANCE(548);
      END_STATE();
    case 445:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'c') ADVANCE(388);
      if (sym_identifier_character_set_4(lookahead)) ADVANCE(548);
      END_STATE();
    case 446:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'c') ADVANCE(494);
      if (lookahead == 'f') ADVANCE(382);
      if (sym_identifier_character_set_4(lookahead)) ADVANCE(548);
      END_STATE();
    case 447:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'c') ADVANCE(494);
      if (sym_identifier_character_set_4(lookahead)) ADVANCE(548);
      END_STATE();
    case 448:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'c') ADVANCE(409);
      if (sym_identifier_character_set_4(lookahead)) ADVANCE(548);
      END_STATE();
    case 449:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'c') ADVANCE(466);
      if (sym_identifier_character_set_4(lookahead)) ADVANCE(548);
      END_STATE();
    case 450:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'c') ADVANCE(468);
      if (sym_identifier_character_set_4(lookahead)) ADVANCE(548);
      END_STATE();
    case 451:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'd') ADVANCE(432);
      if (lookahead == 'l') ADVANCE(489);
      if (sym_identifier_character_set_4(lookahead)) ADVANCE(548);
      END_STATE();
    case 452:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'd') ADVANCE(432);
      if (sym_identifier_character_set_4(lookahead)) ADVANCE(548);
      END_STATE();
    case 453:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'd') ADVANCE(475);
      if (sym_identifier_character_set_4(lookahead)) ADVANCE(548);
      END_STATE();
    case 454:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'd') ADVANCE(502);
      if (sym_identifier_character_set_4(lookahead)) ADVANCE(548);
      END_STATE();
    case 455:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'd') ADVANCE(509);
      if (lookahead == 'r') ADVANCE(507);
      if (sym_identifier_character_set_4(lookahead)) ADVANCE(548);
      END_STATE();
    case 456:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'd') ADVANCE(509);
      if (sym_identifier_character_set_4(lookahead)) ADVANCE(548);
      END_STATE();
    case 457:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'd') ADVANCE(399);
      if (sym_identifier_character_set_4(lookahead)) ADVANCE(548);
      END_STATE();
    case 458:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(516);
      if (lookahead == 'u') ADVANCE(490);
      if (sym_identifier_character_set_4(lookahead)) ADVANCE(548);
      END_STATE();
    case 459:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(525);
      if (sym_identifier_character_set_4(lookahead)) ADVANCE(548);
      END_STATE();
    case 460:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(520);
      if (sym_identifier_character_set_4(lookahead)) ADVANCE(548);
      END_STATE();
    case 461:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(524);
      if (sym_identifier_character_set_4(lookahead)) ADVANCE(548);
      END_STATE();
    case 462:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(421);
      if (sym_identifier_character_set_4(lookahead)) ADVANCE(548);
      END_STATE();
    case 463:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(391);
      if (lookahead == 'i') ADVANCE(448);
      if (sym_identifier_character_set_4(lookahead)) ADVANCE(548);
      END_STATE();
    case 464:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(391);
      if (sym_identifier_character_set_4(lookahead)) ADVANCE(548);
      END_STATE();
    case 465:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(396);
      if (sym_identifier_character_set_4(lookahead)) ADVANCE(548);
      END_STATE();
    case 466:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(394);
      if (sym_identifier_character_set_4(lookahead)) ADVANCE(548);
      END_STATE();
    case 467:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(404);
      if (sym_identifier_character_set_4(lookahead)) ADVANCE(548);
      END_STATE();
    case 468:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(413);
      if (sym_identifier_character_set_4(lookahead)) ADVANCE(548);
      END_STATE();
    case 469:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(534);
      if (sym_identifier_character_set_4(lookahead)) ADVANCE(548);
      END_STATE();
    case 470:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(410);
      if (sym_identifier_character_set_4(lookahead)) ADVANCE(548);
      END_STATE();
    case 471:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(411);
      if (sym_identifier_character_set_4(lookahead)) ADVANCE(548);
      END_STATE();
    case 472:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'f') ADVANCE(382);
      if (sym_identifier_character_set_4(lookahead)) ADVANCE(548);
      END_STATE();
    case 473:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'f') ADVANCE(397);
      if (sym_identifier_character_set_4(lookahead)) ADVANCE(548);
      END_STATE();
    case 474:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'g') ADVANCE(476);
      if (sym_identifier_character_set_4(lookahead)) ADVANCE(548);
      END_STATE();
    case 475:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'g') ADVANCE(471);
      if (sym_identifier_character_set_4(lookahead)) ADVANCE(548);
      END_STATE();
    case 476:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'h') ADVANCE(390);
      if (sym_identifier_character_set_4(lookahead)) ADVANCE(548);
      END_STATE();
    case 477:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'h') ADVANCE(461);
      if (sym_identifier_character_set_4(lookahead)) ADVANCE(548);
      END_STATE();
    case 478:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'i') ADVANCE(497);
      if (lookahead == 'l') ADVANCE(503);
      if (lookahead == 'r') ADVANCE(481);
      if (sym_identifier_character_set_4(lookahead)) ADVANCE(548);
      END_STATE();
    case 479:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'i') ADVANCE(542);
      if (lookahead == 'u') ADVANCE(511);
      if (sym_identifier_character_set_4(lookahead)) ADVANCE(548);
      END_STATE();
    case 480:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'i') ADVANCE(474);
      if (sym_identifier_character_set_4(lookahead)) ADVANCE(548);
      END_STATE();
    case 481:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'i') ADVANCE(453);
      if (sym_identifier_character_set_4(lookahead)) ADVANCE(548);
      END_STATE();
    case 482:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'i') ADVANCE(491);
      if (sym_identifier_character_set_4(lookahead)) ADVANCE(548);
      END_STATE();
    case 483:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'i') ADVANCE(521);
      if (sym_identifier_character_set_4(lookahead)) ADVANCE(548);
      END_STATE();
    case 484:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'i') ADVANCE(543);
      if (sym_identifier_character_set_4(lookahead)) ADVANCE(548);
      END_STATE();
    case 485:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'k') ADVANCE(546);
      if (sym_identifier_character_set_4(lookahead)) ADVANCE(548);
      END_STATE();
    case 486:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'k') ADVANCE(412);
      if (sym_identifier_character_set_4(lookahead)) ADVANCE(548);
      END_STATE();
    case 487:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'l') ADVANCE(503);
      if (sym_identifier_character_set_4(lookahead)) ADVANCE(548);
      END_STATE();
    case 488:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'l') ADVANCE(547);
      if (sym_identifier_character_set_4(lookahead)) ADVANCE(548);
      END_STATE();
    case 489:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'l') ADVANCE(501);
      if (sym_identifier_character_set_4(lookahead)) ADVANCE(548);
      END_STATE();
    case 490:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'l') ADVANCE(459);
      if (sym_identifier_character_set_4(lookahead)) ADVANCE(548);
      END_STATE();
    case 491:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'l') ADVANCE(389);
      if (sym_identifier_character_set_4(lookahead)) ADVANCE(548);
      END_STATE();
    case 492:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'l') ADVANCE(465);
      if (sym_identifier_character_set_4(lookahead)) ADVANCE(548);
      END_STATE();
    case 493:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'm') ADVANCE(508);
      if (sym_identifier_character_set_4(lookahead)) ADVANCE(548);
      END_STATE();
    case 494:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'm') ADVANCE(515);
      if (sym_identifier_character_set_4(lookahead)) ADVANCE(548);
      END_STATE();
    case 495:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'm') ADVANCE(400);
      if (sym_identifier_character_set_4(lookahead)) ADVANCE(548);
      END_STATE();
    case 496:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'n') ADVANCE(454);
      if (sym_identifier_character_set_4(lookahead)) ADVANCE(548);
      END_STATE();
    case 497:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'n') ADVANCE(434);
      if (sym_identifier_character_set_4(lookahead)) ADVANCE(548);
      END_STATE();
    case 498:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'n') ADVANCE(457);
      if (lookahead == 't') ADVANCE(470);
      if (sym_identifier_character_set_4(lookahead)) ADVANCE(548);
      END_STATE();
    case 499:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'n') ADVANCE(395);
      if (sym_identifier_character_set_4(lookahead)) ADVANCE(548);
      END_STATE();
    case 500:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'n') ADVANCE(393);
      if (sym_identifier_character_set_4(lookahead)) ADVANCE(548);
      END_STATE();
    case 501:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'o') ADVANCE(544);
      if (sym_identifier_character_set_4(lookahead)) ADVANCE(548);
      END_STATE();
    case 502:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'o') ADVANCE(495);
      if (sym_identifier_character_set_4(lookahead)) ADVANCE(548);
      END_STATE();
    case 503:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'o') ADVANCE(438);
      if (sym_identifier_character_set_4(lookahead)) ADVANCE(548);
      END_STATE();
    case 504:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'o') ADVANCE(405);
      if (sym_identifier_character_set_4(lookahead)) ADVANCE(548);
      END_STATE();
    case 505:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'o') ADVANCE(403);
      if (sym_identifier_character_set_4(lookahead)) ADVANCE(548);
      END_STATE();
    case 506:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'p') ADVANCE(417);
      if (sym_identifier_character_set_4(lookahead)) ADVANCE(548);
      END_STATE();
    case 507:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'p') ADVANCE(473);
      if (sym_identifier_character_set_4(lookahead)) ADVANCE(548);
      END_STATE();
    case 508:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'p') ADVANCE(398);
      if (sym_identifier_character_set_4(lookahead)) ADVANCE(548);
      END_STATE();
    case 509:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'p') ADVANCE(418);
      if (sym_identifier_character_set_4(lookahead)) ADVANCE(548);
      END_STATE();
    case 510:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'p') ADVANCE(488);
      if (lookahead == 'q') ADVANCE(539);
      if (lookahead == 't') ADVANCE(540);
      if (sym_identifier_character_set_4(lookahead)) ADVANCE(548);
      END_STATE();
    case 511:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'p') ADVANCE(384);
      if (sym_identifier_character_set_4(lookahead)) ADVANCE(548);
      END_STATE();
    case 512:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'p') ADVANCE(420);
      if (sym_identifier_character_set_4(lookahead)) ADVANCE(548);
      END_STATE();
    case 513:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'p') ADVANCE(385);
      if (lookahead == 'x') ADVANCE(568);
      if (sym_identifier_character_set_4(lookahead)) ADVANCE(548);
      END_STATE();
    case 514:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'p') ADVANCE(529);
      if (sym_identifier_character_set_4(lookahead)) ADVANCE(548);
      END_STATE();
    case 515:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'p') ADVANCE(419);
      if (sym_identifier_character_set_4(lookahead)) ADVANCE(548);
      END_STATE();
    case 516:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'q') ADVANCE(539);
      if (sym_identifier_character_set_4(lookahead)) ADVANCE(548);
      END_STATE();
    case 517:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'r') ADVANCE(449);
      if (sym_identifier_character_set_4(lookahead)) ADVANCE(548);
      END_STATE();
    case 518:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'r') ADVANCE(500);
      if (sym_identifier_character_set_4(lookahead)) ADVANCE(548);
      END_STATE();
    case 519:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'r') ADVANCE(445);
      if (sym_identifier_character_set_4(lookahead)) ADVANCE(548);
      END_STATE();
    case 520:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'r') ADVANCE(532);
      if (sym_identifier_character_set_4(lookahead)) ADVANCE(548);
      END_STATE();
    case 521:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'r') ADVANCE(467);
      if (sym_identifier_character_set_4(lookahead)) ADVANCE(548);
      END_STATE();
    case 522:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'r') ADVANCE(450);
      if (sym_identifier_character_set_4(lookahead)) ADVANCE(548);
      END_STATE();
    case 523:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'r') ADVANCE(415);
      if (sym_identifier_character_set_4(lookahead)) ADVANCE(548);
      END_STATE();
    case 524:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'r') ADVANCE(423);
      if (sym_identifier_character_set_4(lookahead)) ADVANCE(548);
      END_STATE();
    case 525:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 's') ADVANCE(469);
      if (sym_identifier_character_set_4(lookahead)) ADVANCE(548);
      END_STATE();
    case 526:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 't') ADVANCE(477);
      if (sym_identifier_character_set_4(lookahead)) ADVANCE(548);
      END_STATE();
    case 527:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 't') ADVANCE(463);
      if (sym_identifier_character_set_4(lookahead)) ADVANCE(548);
      END_STATE();
    case 528:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 't') ADVANCE(433);
      if (sym_identifier_character_set_4(lookahead)) ADVANCE(548);
      END_STATE();
    case 529:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 't') ADVANCE(484);
      if (sym_identifier_character_set_4(lookahead)) ADVANCE(548);
      END_STATE();
    case 530:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 't') ADVANCE(386);
      if (sym_identifier_character_set_4(lookahead)) ADVANCE(548);
      END_STATE();
    case 531:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 't') ADVANCE(512);
      if (sym_identifier_character_set_4(lookahead)) ADVANCE(548);
      END_STATE();
    case 532:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 't') ADVANCE(392);
      if (sym_identifier_character_set_4(lookahead)) ADVANCE(548);
      END_STATE();
    case 533:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 't') ADVANCE(406);
      if (sym_identifier_character_set_4(lookahead)) ADVANCE(548);
      END_STATE();
    case 534:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 't') ADVANCE(407);
      if (sym_identifier_character_set_4(lookahead)) ADVANCE(548);
      END_STATE();
    case 535:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 't') ADVANCE(464);
      if (sym_identifier_character_set_4(lookahead)) ADVANCE(548);
      END_STATE();
    case 536:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 't') ADVANCE(416);
      if (sym_identifier_character_set_4(lookahead)) ADVANCE(548);
      END_STATE();
    case 537:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'u') ADVANCE(498);
      if (sym_identifier_character_set_4(lookahead)) ADVANCE(548);
      END_STATE();
    case 538:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'u') ADVANCE(517);
      if (sym_identifier_character_set_4(lookahead)) ADVANCE(548);
      END_STATE();
    case 539:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'u') ADVANCE(483);
      if (sym_identifier_character_set_4(lookahead)) ADVANCE(548);
      END_STATE();
    case 540:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'u') ADVANCE(518);
      if (sym_identifier_character_set_4(lookahead)) ADVANCE(548);
      END_STATE();
    case 541:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'u') ADVANCE(522);
      if (sym_identifier_character_set_4(lookahead)) ADVANCE(548);
      END_STATE();
    case 542:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'v') ADVANCE(460);
      if (sym_identifier_character_set_4(lookahead)) ADVANCE(548);
      END_STATE();
    case 543:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'v') ADVANCE(462);
      if (sym_identifier_character_set_4(lookahead)) ADVANCE(548);
      END_STATE();
    case 544:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'w') ADVANCE(401);
      if (sym_identifier_character_set_4(lookahead)) ADVANCE(548);
      END_STATE();
    case 545:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'x') ADVANCE(569);
      if (sym_identifier_character_set_4(lookahead)) ADVANCE(548);
      END_STATE();
    case 546:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'y') ADVANCE(402);
      if (sym_identifier_character_set_4(lookahead)) ADVANCE(548);
      END_STATE();
    case 547:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'y') ADVANCE(408);
      if (sym_identifier_character_set_4(lookahead)) ADVANCE(548);
      END_STATE();
    case 548:
      ACCEPT_TOKEN(sym_identifier);
      if (sym_identifier_character_set_4(lookahead)) ADVANCE(548);
      END_STATE();
    case 549:
      ACCEPT_TOKEN(anon_sym_DQUOTE);
      END_STATE();
    case 550:
      ACCEPT_TOKEN(aux_sym_string_token1);
      if (lookahead == '\r') ADVANCE(552);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '"') ADVANCE(552);
      END_STATE();
    case 551:
      ACCEPT_TOKEN(aux_sym_string_token1);
      if (lookahead == '#') ADVANCE(345);
      if (lookahead == '\\') ADVANCE(550);
      if (lookahead == '\t' ||
          (11 <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(551);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '"') ADVANCE(552);
      END_STATE();
    case 552:
      ACCEPT_TOKEN(aux_sym_string_token1);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '"') ADVANCE(552);
      END_STATE();
    case 553:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == 'x') ADVANCE(334);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(554);
      END_STATE();
    case 554:
      ACCEPT_TOKEN(sym_number);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(554);
      END_STATE();
    case 555:
      ACCEPT_TOKEN(sym_hex_number);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(555);
      END_STATE();
    case 556:
      ACCEPT_TOKEN(sym_not_operator);
      END_STATE();
    case 557:
      ACCEPT_TOKEN(sym_allow_opts_keyword);
      END_STATE();
    case 558:
      ACCEPT_TOKEN(sym_binat_anchor_keyword);
      END_STATE();
    case 559:
      ACCEPT_TOKEN(sym_block_policy_keyword);
      END_STATE();
    case 560:
      ACCEPT_TOKEN(sym_bridge_to_keyword);
      END_STATE();
    case 561:
      ACCEPT_TOKEN(sym_divert_reply_keyword);
      END_STATE();
    case 562:
      ACCEPT_TOKEN(sym_divert_to_keyword);
      END_STATE();
    case 563:
      ACCEPT_TOKEN(sym_dup_to_keyword);
      END_STATE();
    case 564:
      ACCEPT_TOKEN(sym_fail_policy_keyword);
      END_STATE();
    case 565:
      ACCEPT_TOKEN(sym_icmp_type_keyword);
      END_STATE();
    case 566:
      ACCEPT_TOKEN(sym_icmp6_type_keyword);
      END_STATE();
    case 567:
      ACCEPT_TOKEN(sym_map_e_portset_keyword);
      END_STATE();
    case 568:
      ACCEPT_TOKEN(sym_max_keyword);
      if (lookahead == '-') ADVANCE(168);
      if (sym_identifier_character_set_4(lookahead)) ADVANCE(548);
      END_STATE();
    case 569:
      ACCEPT_TOKEN(sym_max_keyword);
      if (lookahead == '-') ADVANCE(257);
      if (sym_identifier_character_set_4(lookahead)) ADVANCE(548);
      END_STATE();
    case 570:
      ACCEPT_TOKEN(sym_max_mss_keyword);
      END_STATE();
    case 571:
      ACCEPT_TOKEN(sym_max_src_conn_keyword);
      if (lookahead == '-') ADVANCE(252);
      END_STATE();
    case 572:
      ACCEPT_TOKEN(sym_max_src_conn_rate_keyword);
      END_STATE();
    case 573:
      ACCEPT_TOKEN(sym_max_src_nodes_keyword);
      END_STATE();
    case 574:
      ACCEPT_TOKEN(sym_max_src_states_keyword);
      END_STATE();
    case 575:
      ACCEPT_TOKEN(sym_min_ttl_keyword);
      END_STATE();
    case 576:
      ACCEPT_TOKEN(sym_nat_anchor_keyword);
      END_STATE();
    case 577:
      ACCEPT_TOKEN(sym_no_df_keyword);
      END_STATE();
    case 578:
      ACCEPT_TOKEN(sym_no_route_keyword);
      END_STATE();
    case 579:
      ACCEPT_TOKEN(sym_no_sync_keyword);
      END_STATE();
    case 580:
      ACCEPT_TOKEN(sym_random_id_keyword);
      END_STATE();
    case 581:
      ACCEPT_TOKEN(sym_rdr_anchor_keyword);
      END_STATE();
    case 582:
      ACCEPT_TOKEN(sym_reply_to_keyword);
      END_STATE();
    case 583:
      ACCEPT_TOKEN(sym_require_order_keyword);
      END_STATE();
    case 584:
      ACCEPT_TOKEN(sym_return_icmp_keyword);
      if (lookahead == '6') ADVANCE(585);
      END_STATE();
    case 585:
      ACCEPT_TOKEN(sym_return_icmp6_keyword);
      END_STATE();
    case 586:
      ACCEPT_TOKEN(sym_return_rst_keyword);
      END_STATE();
    case 587:
      ACCEPT_TOKEN(sym_round_robin_keyword);
      END_STATE();
    case 588:
      ACCEPT_TOKEN(sym_route_to_keyword);
      END_STATE();
    case 589:
      ACCEPT_TOKEN(sym_ruleset_optimization_keyword);
      END_STATE();
    case 590:
      ACCEPT_TOKEN(sym_set_tos_keyword);
      END_STATE();
    case 591:
      ACCEPT_TOKEN(sym_source_hash_keyword);
      END_STATE();
    case 592:
      ACCEPT_TOKEN(sym_source_track_keyword);
      END_STATE();
    case 593:
      ACCEPT_TOKEN(sym_state_defaults_keyword);
      END_STATE();
    case 594:
      ACCEPT_TOKEN(sym_state_policy_keyword);
      END_STATE();
    case 595:
      ACCEPT_TOKEN(sym_static_port_keyword);
      END_STATE();
    case 596:
      ACCEPT_TOKEN(sym_sticky_address_keyword);
      END_STATE();
    case 597:
      ACCEPT_TOKEN(sym_urpf_failed_keyword);
      END_STATE();
    default:
      return false;
  }
}

static bool ts_lex_keywords(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (lookahead == '\\') SKIP(1)
      if (lookahead == 'a') ADVANCE(2);
      if (lookahead == 'b') ADVANCE(3);
      if (lookahead == 'c') ADVANCE(4);
      if (lookahead == 'd') ADVANCE(5);
      if (lookahead == 'e') ADVANCE(6);
      if (lookahead == 'f') ADVANCE(7);
      if (lookahead == 'g') ADVANCE(8);
      if (lookahead == 'h') ADVANCE(9);
      if (lookahead == 'i') ADVANCE(10);
      if (lookahead == 'k') ADVANCE(11);
      if (lookahead == 'l') ADVANCE(12);
      if (lookahead == 'm') ADVANCE(13);
      if (lookahead == 'n') ADVANCE(14);
      if (lookahead == 'o') ADVANCE(15);
      if (lookahead == 'p') ADVANCE(16);
      if (lookahead == 'q') ADVANCE(17);
      if (lookahead == 'r') ADVANCE(18);
      if (lookahead == 's') ADVANCE(19);
      if (lookahead == 't') ADVANCE(20);
      if (lookahead == 'u') ADVANCE(21);
      if (lookahead == 'y') ADVANCE(22);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(0)
      END_STATE();
    case 1:
      if (lookahead == '\n') SKIP(0)
      if (lookahead == '\r') SKIP(23)
      END_STATE();
    case 2:
      if (lookahead == 'd') ADVANCE(24);
      if (lookahead == 'g') ADVANCE(25);
      if (lookahead == 'l') ADVANCE(26);
      if (lookahead == 'n') ADVANCE(27);
      END_STATE();
    case 3:
      if (lookahead == 'a') ADVANCE(28);
      if (lookahead == 'i') ADVANCE(29);
      if (lookahead == 'l') ADVANCE(30);
      if (lookahead == 'u') ADVANCE(31);
      END_STATE();
    case 4:
      if (lookahead == 'b') ADVANCE(32);
      if (lookahead == 'o') ADVANCE(33);
      END_STATE();
    case 5:
      if (lookahead == 'e') ADVANCE(34);
      if (lookahead == 'n') ADVANCE(35);
      if (lookahead == 'r') ADVANCE(36);
      END_STATE();
    case 6:
      if (lookahead == 't') ADVANCE(37);
      END_STATE();
    case 7:
      if (lookahead == 'a') ADVANCE(38);
      if (lookahead == 'i') ADVANCE(39);
      if (lookahead == 'l') ADVANCE(40);
      if (lookahead == 'o') ADVANCE(41);
      if (lookahead == 'r') ADVANCE(42);
      END_STATE();
    case 8:
      if (lookahead == 'l') ADVANCE(43);
      if (lookahead == 'r') ADVANCE(44);
      END_STATE();
    case 9:
      if (lookahead == 'f') ADVANCE(45);
      if (lookahead == 'o') ADVANCE(46);
      END_STATE();
    case 10:
      if (lookahead == 'n') ADVANCE(47);
      END_STATE();
    case 11:
      if (lookahead == 'e') ADVANCE(48);
      END_STATE();
    case 12:
      if (lookahead == '3') ADVANCE(49);
      if (lookahead == 'a') ADVANCE(50);
      if (lookahead == 'i') ADVANCE(51);
      if (lookahead == 'o') ADVANCE(52);
      END_STATE();
    case 13:
      if (lookahead == 'a') ADVANCE(53);
      if (lookahead == 'i') ADVANCE(54);
      if (lookahead == 'o') ADVANCE(55);
      END_STATE();
    case 14:
      if (lookahead == 'a') ADVANCE(56);
      if (lookahead == 'e') ADVANCE(57);
      if (lookahead == 'o') ADVANCE(58);
      END_STATE();
    case 15:
      if (lookahead == 'n') ADVANCE(59);
      if (lookahead == 'p') ADVANCE(60);
      if (lookahead == 's') ADVANCE(61);
      if (lookahead == 'u') ADVANCE(62);
      if (lookahead == 'v') ADVANCE(63);
      END_STATE();
    case 16:
      if (lookahead == 'a') ADVANCE(64);
      if (lookahead == 'f') ADVANCE(65);
      if (lookahead == 'o') ADVANCE(66);
      if (lookahead == 'r') ADVANCE(67);
      END_STATE();
    case 17:
      if (lookahead == 'l') ADVANCE(68);
      if (lookahead == 'u') ADVANCE(69);
      END_STATE();
    case 18:
      if (lookahead == 'a') ADVANCE(70);
      if (lookahead == 'd') ADVANCE(71);
      if (lookahead == 'e') ADVANCE(72);
      if (lookahead == 'i') ADVANCE(73);
      if (lookahead == 'o') ADVANCE(74);
      if (lookahead == 't') ADVANCE(75);
      if (lookahead == 'u') ADVANCE(76);
      END_STATE();
    case 19:
      if (lookahead == 'a') ADVANCE(77);
      if (lookahead == 'c') ADVANCE(78);
      if (lookahead == 'e') ADVANCE(79);
      if (lookahead == 'k') ADVANCE(80);
      if (lookahead == 'l') ADVANCE(81);
      if (lookahead == 't') ADVANCE(82);
      if (lookahead == 'y') ADVANCE(83);
      END_STATE();
    case 20:
      if (lookahead == 'a') ADVANCE(84);
      if (lookahead == 'b') ADVANCE(85);
      if (lookahead == 'i') ADVANCE(86);
      if (lookahead == 'o') ADVANCE(87);
      if (lookahead == 't') ADVANCE(88);
      END_STATE();
    case 21:
      if (lookahead == 'p') ADVANCE(89);
      if (lookahead == 'r') ADVANCE(90);
      if (lookahead == 's') ADVANCE(91);
      END_STATE();
    case 22:
      if (lookahead == 'e') ADVANCE(92);
      END_STATE();
    case 23:
      if (lookahead == '\n') SKIP(0)
      END_STATE();
    case 24:
      if (lookahead == 'a') ADVANCE(93);
      END_STATE();
    case 25:
      if (lookahead == 'g') ADVANCE(94);
      END_STATE();
    case 26:
      if (lookahead == 'l') ADVANCE(95);
      if (lookahead == 't') ADVANCE(96);
      if (lookahead == 'w') ADVANCE(97);
      END_STATE();
    case 27:
      if (lookahead == 'c') ADVANCE(98);
      if (lookahead == 't') ADVANCE(99);
      if (lookahead == 'y') ADVANCE(100);
      END_STATE();
    case 28:
      if (lookahead == 'n') ADVANCE(101);
      if (lookahead == 's') ADVANCE(102);
      END_STATE();
    case 29:
      if (lookahead == 'n') ADVANCE(103);
      if (lookahead == 't') ADVANCE(104);
      END_STATE();
    case 30:
      if (lookahead == 'o') ADVANCE(105);
      END_STATE();
    case 31:
      if (lookahead == 'c') ADVANCE(106);
      END_STATE();
    case 32:
      if (lookahead == 'q') ADVANCE(107);
      END_STATE();
    case 33:
      if (lookahead == 'd') ADVANCE(108);
      if (lookahead == 'n') ADVANCE(109);
      END_STATE();
    case 34:
      if (lookahead == 'b') ADVANCE(110);
      END_STATE();
    case 35:
      if (lookahead == 'p') ADVANCE(111);
      if (lookahead == 'q') ADVANCE(112);
      END_STATE();
    case 36:
      if (lookahead == 'o') ADVANCE(113);
      END_STATE();
    case 37:
      if (lookahead == 'h') ADVANCE(114);
      END_STATE();
    case 38:
      if (lookahead == 'i') ADVANCE(115);
      if (lookahead == 's') ADVANCE(116);
      END_STATE();
    case 39:
      if (lookahead == 'l') ADVANCE(117);
      if (lookahead == 'n') ADVANCE(118);
      END_STATE();
    case 40:
      if (lookahead == 'a') ADVANCE(119);
      if (lookahead == 'o') ADVANCE(120);
      if (lookahead == 'u') ADVANCE(121);
      END_STATE();
    case 41:
      if (lookahead == 'r') ADVANCE(122);
      END_STATE();
    case 42:
      if (lookahead == 'a') ADVANCE(123);
      if (lookahead == 'o') ADVANCE(124);
      END_STATE();
    case 43:
      if (lookahead == 'o') ADVANCE(125);
      END_STATE();
    case 44:
      if (lookahead == 'o') ADVANCE(126);
      END_STATE();
    case 45:
      if (lookahead == 's') ADVANCE(127);
      END_STATE();
    case 46:
      if (lookahead == 'g') ADVANCE(128);
      if (lookahead == 's') ADVANCE(129);
      END_STATE();
    case 47:
      ACCEPT_TOKEN(sym_in_keyword);
      if (lookahead == 'c') ADVANCE(130);
      if (lookahead == 'e') ADVANCE(131);
      if (lookahead == 't') ADVANCE(132);
      END_STATE();
    case 48:
      if (lookahead == 'e') ADVANCE(133);
      END_STATE();
    case 49:
      ACCEPT_TOKEN(sym_l3_keyword);
      END_STATE();
    case 50:
      if (lookahead == 'b') ADVANCE(134);
      END_STATE();
    case 51:
      if (lookahead == 'm') ADVANCE(135);
      if (lookahead == 'n') ADVANCE(136);
      END_STATE();
    case 52:
      if (lookahead == 'a') ADVANCE(137);
      if (lookahead == 'g') ADVANCE(138);
      if (lookahead == 'u') ADVANCE(139);
      END_STATE();
    case 53:
      if (lookahead == 't') ADVANCE(140);
      END_STATE();
    case 54:
      if (lookahead == 's') ADVANCE(141);
      END_STATE();
    case 55:
      if (lookahead == 'd') ADVANCE(142);
      END_STATE();
    case 56:
      if (lookahead == 't') ADVANCE(143);
      END_STATE();
    case 57:
      if (lookahead == 'v') ADVANCE(144);
      END_STATE();
    case 58:
      ACCEPT_TOKEN(anon_sym_no);
      if (lookahead == 'n') ADVANCE(145);
      if (lookahead == 'r') ADVANCE(146);
      END_STATE();
    case 59:
      ACCEPT_TOKEN(sym_on_keyword);
      END_STATE();
    case 60:
      if (lookahead == 't') ADVANCE(147);
      END_STATE();
    case 61:
      ACCEPT_TOKEN(sym_os_keyword);
      END_STATE();
    case 62:
      if (lookahead == 't') ADVANCE(148);
      END_STATE();
    case 63:
      if (lookahead == 'e') ADVANCE(149);
      END_STATE();
    case 64:
      if (lookahead == 's') ADVANCE(150);
      END_STATE();
    case 65:
      if (lookahead == 'l') ADVANCE(151);
      END_STATE();
    case 66:
      if (lookahead == 'r') ADVANCE(152);
      END_STATE();
    case 67:
      if (lookahead == 'i') ADVANCE(153);
      if (lookahead == 'o') ADVANCE(154);
      END_STATE();
    case 68:
      if (lookahead == 'i') ADVANCE(155);
      END_STATE();
    case 69:
      if (lookahead == 'e') ADVANCE(156);
      if (lookahead == 'i') ADVANCE(157);
      END_STATE();
    case 70:
      if (lookahead == 'n') ADVANCE(158);
      END_STATE();
    case 71:
      if (lookahead == 'r') ADVANCE(159);
      END_STATE();
    case 72:
      if (lookahead == 'a') ADVANCE(160);
      if (lookahead == 't') ADVANCE(161);
      END_STATE();
    case 73:
      if (lookahead == 'd') ADVANCE(162);
      END_STATE();
    case 74:
      if (lookahead == 'u') ADVANCE(163);
      END_STATE();
    case 75:
      if (lookahead == 'a') ADVANCE(164);
      END_STATE();
    case 76:
      if (lookahead == 'l') ADVANCE(165);
      END_STATE();
    case 77:
      if (lookahead == 't') ADVANCE(166);
      END_STATE();
    case 78:
      if (lookahead == 'r') ADVANCE(167);
      END_STATE();
    case 79:
      if (lookahead == 'l') ADVANCE(168);
      if (lookahead == 't') ADVANCE(169);
      END_STATE();
    case 80:
      if (lookahead == 'i') ADVANCE(170);
      END_STATE();
    case 81:
      if (lookahead == 'o') ADVANCE(171);
      END_STATE();
    case 82:
      if (lookahead == 'a') ADVANCE(172);
      END_STATE();
    case 83:
      if (lookahead == 'n') ADVANCE(173);
      END_STATE();
    case 84:
      if (lookahead == 'b') ADVANCE(174);
      if (lookahead == 'g') ADVANCE(175);
      if (lookahead == 'r') ADVANCE(176);
      END_STATE();
    case 85:
      if (lookahead == 'r') ADVANCE(177);
      END_STATE();
    case 86:
      if (lookahead == 'm') ADVANCE(178);
      END_STATE();
    case 87:
      ACCEPT_TOKEN(sym_to_keyword);
      if (lookahead == 's') ADVANCE(179);
      END_STATE();
    case 88:
      if (lookahead == 'l') ADVANCE(180);
      END_STATE();
    case 89:
      if (lookahead == 'p') ADVANCE(181);
      END_STATE();
    case 90:
      if (lookahead == 'g') ADVANCE(182);
      END_STATE();
    case 91:
      if (lookahead == 'e') ADVANCE(183);
      END_STATE();
    case 92:
      if (lookahead == 's') ADVANCE(184);
      END_STATE();
    case 93:
      if (lookahead == 'p') ADVANCE(185);
      END_STATE();
    case 94:
      if (lookahead == 'r') ADVANCE(186);
      END_STATE();
    case 95:
      ACCEPT_TOKEN(sym_all_keyword);
      END_STATE();
    case 96:
      if (lookahead == 'q') ADVANCE(187);
      END_STATE();
    case 97:
      if (lookahead == 'a') ADVANCE(188);
      END_STATE();
    case 98:
      if (lookahead == 'h') ADVANCE(189);
      END_STATE();
    case 99:
      if (lookahead == 'i') ADVANCE(190);
      END_STATE();
    case 100:
      ACCEPT_TOKEN(sym_any_keyword);
      END_STATE();
    case 101:
      if (lookahead == 'd') ADVANCE(191);
      END_STATE();
    case 102:
      if (lookahead == 'i') ADVANCE(192);
      END_STATE();
    case 103:
      if (lookahead == 'a') ADVANCE(193);
      END_STATE();
    case 104:
      if (lookahead == 'm') ADVANCE(194);
      END_STATE();
    case 105:
      if (lookahead == 'c') ADVANCE(195);
      END_STATE();
    case 106:
      if (lookahead == 'k') ADVANCE(196);
      END_STATE();
    case 107:
      ACCEPT_TOKEN(sym_cbq_keyword);
      END_STATE();
    case 108:
      if (lookahead == 'e') ADVANCE(197);
      END_STATE();
    case 109:
      if (lookahead == 's') ADVANCE(198);
      END_STATE();
    case 110:
      if (lookahead == 'u') ADVANCE(199);
      END_STATE();
    case 111:
      if (lookahead == 'i') ADVANCE(200);
      END_STATE();
    case 112:
      if (lookahead == 'u') ADVANCE(201);
      END_STATE();
    case 113:
      if (lookahead == 'p') ADVANCE(202);
      END_STATE();
    case 114:
      if (lookahead == 'e') ADVANCE(203);
      END_STATE();
    case 115:
      if (lookahead == 'r') ADVANCE(204);
      END_STATE();
    case 116:
      if (lookahead == 't') ADVANCE(205);
      END_STATE();
    case 117:
      if (lookahead == 'e') ADVANCE(206);
      END_STATE();
    case 118:
      if (lookahead == 'g') ADVANCE(207);
      END_STATE();
    case 119:
      if (lookahead == 'g') ADVANCE(208);
      END_STATE();
    case 120:
      if (lookahead == 'a') ADVANCE(209);
      END_STATE();
    case 121:
      if (lookahead == 's') ADVANCE(210);
      END_STATE();
    case 122:
      ACCEPT_TOKEN(sym_for_keyword);
      END_STATE();
    case 123:
      if (lookahead == 'g') ADVANCE(211);
      END_STATE();
    case 124:
      if (lookahead == 'm') ADVANCE(212);
      END_STATE();
    case 125:
      if (lookahead == 'b') ADVANCE(213);
      END_STATE();
    case 126:
      if (lookahead == 'u') ADVANCE(214);
      END_STATE();
    case 127:
      if (lookahead == 'c') ADVANCE(215);
      END_STATE();
    case 128:
      if (lookahead == 's') ADVANCE(216);
      END_STATE();
    case 129:
      if (lookahead == 't') ADVANCE(217);
      END_STATE();
    case 130:
      if (lookahead == 'l') ADVANCE(218);
      END_STATE();
    case 131:
      if (lookahead == 't') ADVANCE(219);
      END_STATE();
    case 132:
      if (lookahead == 'e') ADVANCE(220);
      END_STATE();
    case 133:
      if (lookahead == 'p') ADVANCE(221);
      END_STATE();
    case 134:
      if (lookahead == 'e') ADVANCE(222);
      END_STATE();
    case 135:
      if (lookahead == 'i') ADVANCE(223);
      END_STATE();
    case 136:
      if (lookahead == 'k') ADVANCE(224);
      END_STATE();
    case 137:
      if (lookahead == 'd') ADVANCE(225);
      END_STATE();
    case 138:
      ACCEPT_TOKEN(sym_log_keyword);
      if (lookahead == 'i') ADVANCE(226);
      END_STATE();
    case 139:
      if (lookahead == 'd') ADVANCE(227);
      END_STATE();
    case 140:
      if (lookahead == 'c') ADVANCE(228);
      END_STATE();
    case 141:
      if (lookahead == 'c') ADVANCE(229);
      END_STATE();
    case 142:
      if (lookahead == 'u') ADVANCE(230);
      END_STATE();
    case 143:
      ACCEPT_TOKEN(sym_nat_keyword);
      END_STATE();
    case 144:
      if (lookahead == 'e') ADVANCE(231);
      END_STATE();
    case 145:
      if (lookahead == 'e') ADVANCE(232);
      END_STATE();
    case 146:
      if (lookahead == 'm') ADVANCE(233);
      END_STATE();
    case 147:
      if (lookahead == 'i') ADVANCE(234);
      END_STATE();
    case 148:
      ACCEPT_TOKEN(sym_out_keyword);
      END_STATE();
    case 149:
      if (lookahead == 'r') ADVANCE(235);
      END_STATE();
    case 150:
      if (lookahead == 's') ADVANCE(236);
      END_STATE();
    case 151:
      if (lookahead == 'o') ADVANCE(237);
      END_STATE();
    case 152:
      if (lookahead == 't') ADVANCE(238);
      END_STATE();
    case 153:
      if (lookahead == 'o') ADVANCE(239);
      if (lookahead == 'q') ADVANCE(240);
      END_STATE();
    case 154:
      if (lookahead == 'b') ADVANCE(241);
      if (lookahead == 'f') ADVANCE(242);
      if (lookahead == 't') ADVANCE(243);
      END_STATE();
    case 155:
      if (lookahead == 'm') ADVANCE(244);
      END_STATE();
    case 156:
      if (lookahead == 'u') ADVANCE(245);
      END_STATE();
    case 157:
      if (lookahead == 'c') ADVANCE(246);
      END_STATE();
    case 158:
      if (lookahead == 'd') ADVANCE(247);
      END_STATE();
    case 159:
      ACCEPT_TOKEN(sym_rdr_keyword);
      END_STATE();
    case 160:
      if (lookahead == 'l') ADVANCE(248);
      if (lookahead == 's') ADVANCE(249);
      END_STATE();
    case 161:
      if (lookahead == 'u') ADVANCE(250);
      END_STATE();
    case 162:
      if (lookahead == 'e') ADVANCE(251);
      END_STATE();
    case 163:
      if (lookahead == 't') ADVANCE(252);
      END_STATE();
    case 164:
      if (lookahead == 'b') ADVANCE(253);
      END_STATE();
    case 165:
      if (lookahead == 'e') ADVANCE(254);
      END_STATE();
    case 166:
      if (lookahead == 'e') ADVANCE(255);
      END_STATE();
    case 167:
      if (lookahead == 'u') ADVANCE(256);
      END_STATE();
    case 168:
      if (lookahead == 'f') ADVANCE(257);
      END_STATE();
    case 169:
      ACCEPT_TOKEN(sym_set_keyword);
      END_STATE();
    case 170:
      if (lookahead == 'p') ADVANCE(258);
      END_STATE();
    case 171:
      if (lookahead == 'p') ADVANCE(259);
      END_STATE();
    case 172:
      if (lookahead == 't') ADVANCE(260);
      END_STATE();
    case 173:
      if (lookahead == 'c') ADVANCE(261);
      if (lookahead == 'p') ADVANCE(262);
      END_STATE();
    case 174:
      if (lookahead == 'l') ADVANCE(263);
      END_STATE();
    case 175:
      ACCEPT_TOKEN(sym_tag_keyword);
      if (lookahead == 'g') ADVANCE(264);
      END_STATE();
    case 176:
      if (lookahead == 'g') ADVANCE(265);
      END_STATE();
    case 177:
      if (lookahead == 's') ADVANCE(266);
      END_STATE();
    case 178:
      if (lookahead == 'e') ADVANCE(267);
      END_STATE();
    case 179:
      ACCEPT_TOKEN(sym_tos_keyword);
      END_STATE();
    case 180:
      ACCEPT_TOKEN(sym_ttl_keyword);
      END_STATE();
    case 181:
      if (lookahead == 'e') ADVANCE(268);
      END_STATE();
    case 182:
      if (lookahead == 'e') ADVANCE(269);
      END_STATE();
    case 183:
      if (lookahead == 'r') ADVANCE(270);
      END_STATE();
    case 184:
      ACCEPT_TOKEN(anon_sym_yes);
      END_STATE();
    case 185:
      if (lookahead == 't') ADVANCE(271);
      END_STATE();
    case 186:
      if (lookahead == 'e') ADVANCE(272);
      END_STATE();
    case 187:
      ACCEPT_TOKEN(sym_altq_keyword);
      END_STATE();
    case 188:
      if (lookahead == 'y') ADVANCE(273);
      END_STATE();
    case 189:
      if (lookahead == 'o') ADVANCE(274);
      END_STATE();
    case 190:
      if (lookahead == 's') ADVANCE(275);
      END_STATE();
    case 191:
      if (lookahead == 'w') ADVANCE(276);
      END_STATE();
    case 192:
      if (lookahead == 'c') ADVANCE(277);
      END_STATE();
    case 193:
      if (lookahead == 't') ADVANCE(278);
      END_STATE();
    case 194:
      if (lookahead == 'a') ADVANCE(279);
      END_STATE();
    case 195:
      if (lookahead == 'k') ADVANCE(280);
      END_STATE();
    case 196:
      if (lookahead == 'e') ADVANCE(281);
      END_STATE();
    case 197:
      ACCEPT_TOKEN(sym_code_keyword);
      if (lookahead == 'l') ADVANCE(282);
      END_STATE();
    case 198:
      if (lookahead == 'e') ADVANCE(283);
      END_STATE();
    case 199:
      if (lookahead == 'g') ADVANCE(284);
      END_STATE();
    case 200:
      if (lookahead == 'p') ADVANCE(285);
      END_STATE();
    case 201:
      if (lookahead == 'e') ADVANCE(286);
      END_STATE();
    case 202:
      ACCEPT_TOKEN(sym_drop_keyword);
      END_STATE();
    case 203:
      if (lookahead == 'r') ADVANCE(287);
      END_STATE();
    case 204:
      if (lookahead == 'q') ADVANCE(288);
      END_STATE();
    case 205:
      if (lookahead == 'r') ADVANCE(289);
      END_STATE();
    case 206:
      ACCEPT_TOKEN(sym_file_keyword);
      END_STATE();
    case 207:
      if (lookahead == 'e') ADVANCE(290);
      END_STATE();
    case 208:
      if (lookahead == 's') ADVANCE(291);
      END_STATE();
    case 209:
      if (lookahead == 't') ADVANCE(292);
      END_STATE();
    case 210:
      if (lookahead == 'h') ADVANCE(293);
      END_STATE();
    case 211:
      ACCEPT_TOKEN(anon_sym_frag);
      if (lookahead == 'm') ADVANCE(294);
      if (lookahead == 's') ADVANCE(295);
      END_STATE();
    case 212:
      ACCEPT_TOKEN(sym_from_keyword);
      END_STATE();
    case 213:
      if (lookahead == 'a') ADVANCE(296);
      END_STATE();
    case 214:
      if (lookahead == 'p') ADVANCE(297);
      END_STATE();
    case 215:
      ACCEPT_TOKEN(sym_hfsc_keyword);
      END_STATE();
    case 216:
      ACCEPT_TOKEN(sym_hogs_keyword);
      END_STATE();
    case 217:
      if (lookahead == 'i') ADVANCE(298);
      END_STATE();
    case 218:
      if (lookahead == 'u') ADVANCE(299);
      END_STATE();
    case 219:
      ACCEPT_TOKEN(sym_inet_keyword);
      if (lookahead == '6') ADVANCE(300);
      END_STATE();
    case 220:
      if (lookahead == 'r') ADVANCE(301);
      END_STATE();
    case 221:
      ACCEPT_TOKEN(sym_keep_keyword);
      if (lookahead == 'c') ADVANCE(302);
      END_STATE();
    case 222:
      if (lookahead == 'l') ADVANCE(303);
      END_STATE();
    case 223:
      if (lookahead == 't') ADVANCE(304);
      END_STATE();
    case 224:
      if (lookahead == 's') ADVANCE(305);
      END_STATE();
    case 225:
      ACCEPT_TOKEN(sym_load_keyword);
      END_STATE();
    case 226:
      if (lookahead == 'n') ADVANCE(306);
      END_STATE();
    case 227:
      ACCEPT_TOKEN(anon_sym_loud);
      END_STATE();
    case 228:
      if (lookahead == 'h') ADVANCE(307);
      END_STATE();
    case 229:
      ACCEPT_TOKEN(anon_sym_misc);
      END_STATE();
    case 230:
      if (lookahead == 'l') ADVANCE(308);
      END_STATE();
    case 231:
      if (lookahead == 'r') ADVANCE(309);
      END_STATE();
    case 232:
      ACCEPT_TOKEN(anon_sym_none);
      END_STATE();
    case 233:
      if (lookahead == 'a') ADVANCE(310);
      END_STATE();
    case 234:
      if (lookahead == 'm') ADVANCE(311);
      END_STATE();
    case 235:
      if (lookahead == 'l') ADVANCE(312);
      END_STATE();
    case 236:
      ACCEPT_TOKEN(sym_pass_keyword);
      END_STATE();
    case 237:
      if (lookahead == 'w') ADVANCE(313);
      END_STATE();
    case 238:
      ACCEPT_TOKEN(sym_port_keyword);
      END_STATE();
    case 239:
      ACCEPT_TOKEN(sym_prio_keyword);
      if (lookahead == 'r') ADVANCE(314);
      END_STATE();
    case 240:
      ACCEPT_TOKEN(sym_priq_keyword);
      END_STATE();
    case 241:
      if (lookahead == 'a') ADVANCE(315);
      END_STATE();
    case 242:
      if (lookahead == 'i') ADVANCE(316);
      END_STATE();
    case 243:
      if (lookahead == 'o') ADVANCE(317);
      END_STATE();
    case 244:
      if (lookahead == 'i') ADVANCE(318);
      END_STATE();
    case 245:
      if (lookahead == 'e') ADVANCE(319);
      END_STATE();
    case 246:
      if (lookahead == 'k') ADVANCE(320);
      END_STATE();
    case 247:
      if (lookahead == 'o') ADVANCE(321);
      END_STATE();
    case 248:
      if (lookahead == 't') ADVANCE(322);
      END_STATE();
    case 249:
      if (lookahead == 's') ADVANCE(323);
      END_STATE();
    case 250:
      if (lookahead == 'r') ADVANCE(324);
      END_STATE();
    case 251:
      if (lookahead == 'n') ADVANCE(325);
      END_STATE();
    case 252:
      if (lookahead == 'e') ADVANCE(326);
      END_STATE();
    case 253:
      if (lookahead == 'l') ADVANCE(327);
      END_STATE();
    case 254:
      ACCEPT_TOKEN(sym_rule_keyword);
      END_STATE();
    case 255:
      if (lookahead == 'l') ADVANCE(328);
      END_STATE();
    case 256:
      if (lookahead == 'b') ADVANCE(329);
      END_STATE();
    case 257:
      ACCEPT_TOKEN(sym_self_keyword);
      END_STATE();
    case 258:
      ACCEPT_TOKEN(sym_skip_keyword);
      END_STATE();
    case 259:
      if (lookahead == 'p') ADVANCE(330);
      END_STATE();
    case 260:
      if (lookahead == 'e') ADVANCE(331);
      END_STATE();
    case 261:
      if (lookahead == 'o') ADVANCE(332);
      END_STATE();
    case 262:
      if (lookahead == 'r') ADVANCE(333);
      END_STATE();
    case 263:
      if (lookahead == 'e') ADVANCE(334);
      END_STATE();
    case 264:
      if (lookahead == 'e') ADVANCE(335);
      END_STATE();
    case 265:
      if (lookahead == 'e') ADVANCE(336);
      END_STATE();
    case 266:
      if (lookahead == 'i') ADVANCE(337);
      END_STATE();
    case 267:
      if (lookahead == 'o') ADVANCE(338);
      END_STATE();
    case 268:
      if (lookahead == 'r') ADVANCE(339);
      END_STATE();
    case 269:
      if (lookahead == 'n') ADVANCE(340);
      END_STATE();
    case 270:
      ACCEPT_TOKEN(sym_user_keyword);
      END_STATE();
    case 271:
      if (lookahead == 'a') ADVANCE(341);
      END_STATE();
    case 272:
      if (lookahead == 's') ADVANCE(342);
      END_STATE();
    case 273:
      if (lookahead == 's') ADVANCE(343);
      END_STATE();
    case 274:
      if (lookahead == 'r') ADVANCE(344);
      END_STATE();
    case 275:
      if (lookahead == 'p') ADVANCE(345);
      END_STATE();
    case 276:
      if (lookahead == 'i') ADVANCE(346);
      END_STATE();
    case 277:
      ACCEPT_TOKEN(anon_sym_basic);
      END_STATE();
    case 278:
      ACCEPT_TOKEN(sym_binat_keyword);
      END_STATE();
    case 279:
      if (lookahead == 's') ADVANCE(347);
      END_STATE();
    case 280:
      ACCEPT_TOKEN(sym_block_keyword);
      END_STATE();
    case 281:
      if (lookahead == 't') ADVANCE(348);
      END_STATE();
    case 282:
      if (lookahead == 'q') ADVANCE(349);
      END_STATE();
    case 283:
      if (lookahead == 'r') ADVANCE(350);
      END_STATE();
    case 284:
      ACCEPT_TOKEN(sym_debug_keyword);
      END_STATE();
    case 285:
      if (lookahead == 'e') ADVANCE(351);
      END_STATE();
    case 286:
      if (lookahead == 'u') ADVANCE(352);
      END_STATE();
    case 287:
      ACCEPT_TOKEN(sym_ether_keyword);
      END_STATE();
    case 288:
      ACCEPT_TOKEN(sym_fairq_keyword);
      END_STATE();
    case 289:
      if (lookahead == 'o') ADVANCE(353);
      END_STATE();
    case 290:
      if (lookahead == 'r') ADVANCE(354);
      END_STATE();
    case 291:
      ACCEPT_TOKEN(sym_flags_keyword);
      END_STATE();
    case 292:
      if (lookahead == 'i') ADVANCE(355);
      END_STATE();
    case 293:
      ACCEPT_TOKEN(sym_flush_keyword);
      END_STATE();
    case 294:
      if (lookahead == 'e') ADVANCE(356);
      END_STATE();
    case 295:
      ACCEPT_TOKEN(anon_sym_frags);
      END_STATE();
    case 296:
      if (lookahead == 'l') ADVANCE(357);
      END_STATE();
    case 297:
      ACCEPT_TOKEN(sym_group_keyword);
      END_STATE();
    case 298:
      if (lookahead == 'd') ADVANCE(358);
      END_STATE();
    case 299:
      if (lookahead == 'd') ADVANCE(359);
      END_STATE();
    case 300:
      ACCEPT_TOKEN(sym_inet6_keyword);
      END_STATE();
    case 301:
      if (lookahead == 'v') ADVANCE(360);
      END_STATE();
    case 302:
      if (lookahead == 'o') ADVANCE(361);
      END_STATE();
    case 303:
      ACCEPT_TOKEN(sym_label_keyword);
      END_STATE();
    case 304:
      ACCEPT_TOKEN(sym_limit_keyword);
      END_STATE();
    case 305:
      if (lookahead == 'h') ADVANCE(362);
      END_STATE();
    case 306:
      if (lookahead == 't') ADVANCE(363);
      END_STATE();
    case 307:
      ACCEPT_TOKEN(sym_match_keyword);
      END_STATE();
    case 308:
      if (lookahead == 'a') ADVANCE(364);
      END_STATE();
    case 309:
      ACCEPT_TOKEN(anon_sym_never);
      END_STATE();
    case 310:
      if (lookahead == 'l') ADVANCE(365);
      END_STATE();
    case 311:
      if (lookahead == 'i') ADVANCE(366);
      END_STATE();
    case 312:
      if (lookahead == 'o') ADVANCE(367);
      END_STATE();
    case 313:
      ACCEPT_TOKEN(sym_pflow_keyword);
      END_STATE();
    case 314:
      if (lookahead == 'i') ADVANCE(368);
      END_STATE();
    case 315:
      if (lookahead == 'b') ADVANCE(369);
      END_STATE();
    case 316:
      if (lookahead == 'l') ADVANCE(370);
      END_STATE();
    case 317:
      ACCEPT_TOKEN(sym_proto_keyword);
      END_STATE();
    case 318:
      if (lookahead == 't') ADVANCE(371);
      END_STATE();
    case 319:
      ACCEPT_TOKEN(sym_queue_keyword);
      END_STATE();
    case 320:
      ACCEPT_TOKEN(sym_quick_keyword);
      END_STATE();
    case 321:
      if (lookahead == 'm') ADVANCE(372);
      END_STATE();
    case 322:
      if (lookahead == 'i') ADVANCE(373);
      END_STATE();
    case 323:
      if (lookahead == 'e') ADVANCE(374);
      END_STATE();
    case 324:
      if (lookahead == 'n') ADVANCE(375);
      END_STATE();
    case 325:
      if (lookahead == 't') ADVANCE(376);
      END_STATE();
    case 326:
      ACCEPT_TOKEN(sym_route_keyword);
      END_STATE();
    case 327:
      if (lookahead == 'e') ADVANCE(377);
      END_STATE();
    case 328:
      if (lookahead == 'l') ADVANCE(378);
      END_STATE();
    case 329:
      ACCEPT_TOKEN(sym_scrub_keyword);
      END_STATE();
    case 330:
      if (lookahead == 'y') ADVANCE(379);
      END_STATE();
    case 331:
      ACCEPT_TOKEN(sym_state_keyword);
      if (lookahead == 's') ADVANCE(380);
      END_STATE();
    case 332:
      if (lookahead == 'o') ADVANCE(381);
      END_STATE();
    case 333:
      if (lookahead == 'o') ADVANCE(382);
      END_STATE();
    case 334:
      ACCEPT_TOKEN(sym_table_keyword);
      END_STATE();
    case 335:
      if (lookahead == 'd') ADVANCE(383);
      END_STATE();
    case 336:
      if (lookahead == 't') ADVANCE(384);
      END_STATE();
    case 337:
      if (lookahead == 'z') ADVANCE(385);
      END_STATE();
    case 338:
      if (lookahead == 'u') ADVANCE(386);
      END_STATE();
    case 339:
      if (lookahead == 'l') ADVANCE(387);
      END_STATE();
    case 340:
      if (lookahead == 't') ADVANCE(388);
      END_STATE();
    case 341:
      if (lookahead == 't') ADVANCE(389);
      END_STATE();
    case 342:
      if (lookahead == 's') ADVANCE(390);
      END_STATE();
    case 343:
      ACCEPT_TOKEN(anon_sym_always);
      END_STATE();
    case 344:
      ACCEPT_TOKEN(sym_anchor_keyword);
      END_STATE();
    case 345:
      if (lookahead == 'o') ADVANCE(391);
      END_STATE();
    case 346:
      if (lookahead == 'd') ADVANCE(392);
      END_STATE();
    case 347:
      if (lookahead == 'k') ADVANCE(393);
      END_STATE();
    case 348:
      if (lookahead == 's') ADVANCE(394);
      END_STATE();
    case 349:
      ACCEPT_TOKEN(sym_codelq_keyword);
      END_STATE();
    case 350:
      if (lookahead == 'v') ADVANCE(395);
      END_STATE();
    case 351:
      ACCEPT_TOKEN(sym_dnpipe_keyword);
      END_STATE();
    case 352:
      if (lookahead == 'e') ADVANCE(396);
      END_STATE();
    case 353:
      if (lookahead == 'u') ADVANCE(397);
      END_STATE();
    case 354:
      if (lookahead == 'p') ADVANCE(398);
      END_STATE();
    case 355:
      if (lookahead == 'n') ADVANCE(399);
      END_STATE();
    case 356:
      if (lookahead == 'n') ADVANCE(400);
      END_STATE();
    case 357:
      ACCEPT_TOKEN(sym_global_keyword);
      END_STATE();
    case 358:
      ACCEPT_TOKEN(sym_hostid_keyword);
      END_STATE();
    case 359:
      if (lookahead == 'e') ADVANCE(401);
      END_STATE();
    case 360:
      if (lookahead == 'a') ADVANCE(402);
      END_STATE();
    case 361:
      if (lookahead == 'u') ADVANCE(403);
      END_STATE();
    case 362:
      if (lookahead == 'a') ADVANCE(404);
      END_STATE();
    case 363:
      if (lookahead == 'e') ADVANCE(405);
      END_STATE();
    case 364:
      if (lookahead == 't') ADVANCE(406);
      END_STATE();
    case 365:
      ACCEPT_TOKEN(anon_sym_normal);
      END_STATE();
    case 366:
      if (lookahead == 'z') ADVANCE(407);
      END_STATE();
    case 367:
      if (lookahead == 'a') ADVANCE(408);
      END_STATE();
    case 368:
      if (lookahead == 't') ADVANCE(409);
      END_STATE();
    case 369:
      if (lookahead == 'i') ADVANCE(410);
      END_STATE();
    case 370:
      if (lookahead == 'e') ADVANCE(411);
      END_STATE();
    case 371:
      ACCEPT_TOKEN(sym_qlimit_keyword);
      END_STATE();
    case 372:
      ACCEPT_TOKEN(sym_random_keyword);
      END_STATE();
    case 373:
      if (lookahead == 'm') ADVANCE(412);
      END_STATE();
    case 374:
      if (lookahead == 'm') ADVANCE(413);
      END_STATE();
    case 375:
      ACCEPT_TOKEN(sym_return_keyword);
      END_STATE();
    case 376:
      if (lookahead == 'i') ADVANCE(414);
      END_STATE();
    case 377:
      ACCEPT_TOKEN(sym_rtable_keyword);
      END_STATE();
    case 378:
      if (lookahead == 'i') ADVANCE(415);
      END_STATE();
    case 379:
      ACCEPT_TOKEN(sym_sloppy_keyword);
      END_STATE();
    case 380:
      ACCEPT_TOKEN(anon_sym_states);
      END_STATE();
    case 381:
      if (lookahead == 'k') ADVANCE(416);
      END_STATE();
    case 382:
      if (lookahead == 'x') ADVANCE(417);
      END_STATE();
    case 383:
      ACCEPT_TOKEN(sym_tagged_keyword);
      END_STATE();
    case 384:
      ACCEPT_TOKEN(sym_target_keyword);
      END_STATE();
    case 385:
      if (lookahead == 'e') ADVANCE(418);
      END_STATE();
    case 386:
      if (lookahead == 't') ADVANCE(419);
      END_STATE();
    case 387:
      if (lookahead == 'i') ADVANCE(420);
      END_STATE();
    case 388:
      ACCEPT_TOKEN(anon_sym_urgent);
      END_STATE();
    case 389:
      if (lookahead == 'i') ADVANCE(421);
      END_STATE();
    case 390:
      if (lookahead == 'i') ADVANCE(422);
      END_STATE();
    case 391:
      if (lookahead == 'o') ADVANCE(423);
      END_STATE();
    case 392:
      if (lookahead == 't') ADVANCE(424);
      END_STATE();
    case 393:
      ACCEPT_TOKEN(sym_bitmask_keyword);
      END_STATE();
    case 394:
      ACCEPT_TOKEN(sym_buckets_keyword);
      END_STATE();
    case 395:
      if (lookahead == 'a') ADVANCE(425);
      END_STATE();
    case 396:
      ACCEPT_TOKEN(sym_dnqueue_keyword);
      END_STATE();
    case 397:
      if (lookahead == 't') ADVANCE(426);
      END_STATE();
    case 398:
      if (lookahead == 'r') ADVANCE(427);
      END_STATE();
    case 399:
      if (lookahead == 'g') ADVANCE(428);
      END_STATE();
    case 400:
      if (lookahead == 't') ADVANCE(429);
      END_STATE();
    case 401:
      ACCEPT_TOKEN(sym_include_keyword);
      END_STATE();
    case 402:
      if (lookahead == 'l') ADVANCE(430);
      END_STATE();
    case 403:
      if (lookahead == 'n') ADVANCE(431);
      END_STATE();
    case 404:
      if (lookahead == 'r') ADVANCE(432);
      END_STATE();
    case 405:
      if (lookahead == 'r') ADVANCE(433);
      END_STATE();
    case 406:
      if (lookahead == 'e') ADVANCE(434);
      END_STATE();
    case 407:
      if (lookahead == 'a') ADVANCE(435);
      END_STATE();
    case 408:
      if (lookahead == 'd') ADVANCE(436);
      END_STATE();
    case 409:
      if (lookahead == 'y') ADVANCE(437);
      END_STATE();
    case 410:
      if (lookahead == 'l') ADVANCE(438);
      END_STATE();
    case 411:
      ACCEPT_TOKEN(anon_sym_profile);
      END_STATE();
    case 412:
      if (lookahead == 'e') ADVANCE(439);
      END_STATE();
    case 413:
      if (lookahead == 'b') ADVANCE(440);
      END_STATE();
    case 414:
      if (lookahead == 'f') ADVANCE(441);
      END_STATE();
    case 415:
      if (lookahead == 't') ADVANCE(442);
      END_STATE();
    case 416:
      if (lookahead == 'i') ADVANCE(443);
      END_STATE();
    case 417:
      if (lookahead == 'y') ADVANCE(444);
      END_STATE();
    case 418:
      ACCEPT_TOKEN(sym_tbrsize_keyword);
      END_STATE();
    case 419:
      ACCEPT_TOKEN(sym_timeout_keyword);
      END_STATE();
    case 420:
      if (lookahead == 'm') ADVANCE(445);
      END_STATE();
    case 421:
      if (lookahead == 'v') ADVANCE(446);
      END_STATE();
    case 422:
      if (lookahead == 'v') ADVANCE(447);
      END_STATE();
    case 423:
      if (lookahead == 'f') ADVANCE(448);
      END_STATE();
    case 424:
      if (lookahead == 'h') ADVANCE(449);
      END_STATE();
    case 425:
      if (lookahead == 't') ADVANCE(450);
      END_STATE();
    case 426:
      if (lookahead == 'e') ADVANCE(451);
      END_STATE();
    case 427:
      if (lookahead == 'i') ADVANCE(452);
      END_STATE();
    case 428:
      ACCEPT_TOKEN(anon_sym_floating);
      END_STATE();
    case 429:
      ACCEPT_TOKEN(sym_fragment_keyword);
      END_STATE();
    case 430:
      ACCEPT_TOKEN(anon_sym_interval);
      END_STATE();
    case 431:
      if (lookahead == 't') ADVANCE(453);
      END_STATE();
    case 432:
      if (lookahead == 'e') ADVANCE(454);
      END_STATE();
    case 433:
      if (lookahead == 'f') ADVANCE(455);
      END_STATE();
    case 434:
      ACCEPT_TOKEN(sym_modulate_keyword);
      END_STATE();
    case 435:
      if (lookahead == 't') ADVANCE(456);
      END_STATE();
    case 436:
      ACCEPT_TOKEN(sym_overload_keyword);
      END_STATE();
    case 437:
      ACCEPT_TOKEN(sym_priority_keyword);
      END_STATE();
    case 438:
      if (lookahead == 'i') ADVANCE(457);
      END_STATE();
    case 439:
      ACCEPT_TOKEN(sym_realtime_keyword);
      END_STATE();
    case 440:
      if (lookahead == 'l') ADVANCE(458);
      END_STATE();
    case 441:
      if (lookahead == 'i') ADVANCE(459);
      END_STATE();
    case 442:
      if (lookahead == 'e') ADVANCE(460);
      END_STATE();
    case 443:
      if (lookahead == 'e') ADVANCE(461);
      END_STATE();
    case 444:
      ACCEPT_TOKEN(sym_synproxy_keyword);
      END_STATE();
    case 445:
      if (lookahead == 'i') ADVANCE(462);
      END_STATE();
    case 446:
      if (lookahead == 'e') ADVANCE(463);
      END_STATE();
    case 447:
      if (lookahead == 'e') ADVANCE(464);
      END_STATE();
    case 448:
      ACCEPT_TOKEN(sym_antispoof_keyword);
      END_STATE();
    case 449:
      ACCEPT_TOKEN(sym_bandwidth_keyword);
      END_STATE();
    case 450:
      if (lookahead == 'i') ADVANCE(465);
      END_STATE();
    case 451:
      ACCEPT_TOKEN(sym_fastroute_keyword);
      END_STATE();
    case 452:
      if (lookahead == 'n') ADVANCE(466);
      END_STATE();
    case 453:
      if (lookahead == 'e') ADVANCE(467);
      END_STATE();
    case 454:
      ACCEPT_TOKEN(sym_linkshare_keyword);
      END_STATE();
    case 455:
      if (lookahead == 'a') ADVANCE(468);
      END_STATE();
    case 456:
      if (lookahead == 'i') ADVANCE(469);
      END_STATE();
    case 457:
      if (lookahead == 't') ADVANCE(470);
      END_STATE();
    case 458:
      if (lookahead == 'e') ADVANCE(471);
      END_STATE();
    case 459:
      if (lookahead == 'e') ADVANCE(472);
      END_STATE();
    case 460:
      ACCEPT_TOKEN(anon_sym_satellite);
      END_STATE();
    case 461:
      if (lookahead == 's') ADVANCE(473);
      END_STATE();
    case 462:
      if (lookahead == 't') ADVANCE(474);
      END_STATE();
    case 463:
      ACCEPT_TOKEN(anon_sym_adaptative);
      END_STATE();
    case 464:
      ACCEPT_TOKEN(anon_sym_aggressive);
      END_STATE();
    case 465:
      if (lookahead == 'v') ADVANCE(475);
      END_STATE();
    case 466:
      if (lookahead == 't') ADVANCE(476);
      END_STATE();
    case 467:
      if (lookahead == 'r') ADVANCE(477);
      END_STATE();
    case 468:
      if (lookahead == 'c') ADVANCE(478);
      END_STATE();
    case 469:
      if (lookahead == 'o') ADVANCE(479);
      END_STATE();
    case 470:
      if (lookahead == 'y') ADVANCE(480);
      END_STATE();
    case 471:
      ACCEPT_TOKEN(sym_reassemble_keyword);
      END_STATE();
    case 472:
      if (lookahead == 'r') ADVANCE(481);
      END_STATE();
    case 473:
      ACCEPT_TOKEN(sym_syncookies_keyword);
      END_STATE();
    case 474:
      ACCEPT_TOKEN(sym_upperlimit_keyword);
      END_STATE();
    case 475:
      if (lookahead == 'e') ADVANCE(482);
      END_STATE();
    case 476:
      if (lookahead == 's') ADVANCE(483);
      END_STATE();
    case 477:
      if (lookahead == 's') ADVANCE(484);
      END_STATE();
    case 478:
      if (lookahead == 'e') ADVANCE(485);
      END_STATE();
    case 479:
      if (lookahead == 'n') ADVANCE(486);
      END_STATE();
    case 480:
      ACCEPT_TOKEN(sym_probability_keyword);
      END_STATE();
    case 481:
      ACCEPT_TOKEN(sym_ridentifier_keyword);
      END_STATE();
    case 482:
      ACCEPT_TOKEN(anon_sym_conservative);
      END_STATE();
    case 483:
      ACCEPT_TOKEN(sym_fingerprints_keyword);
      END_STATE();
    case 484:
      ACCEPT_TOKEN(sym_keepcounters_keyword);
      END_STATE();
    case 485:
      ACCEPT_TOKEN(sym_loginterface_keyword);
      END_STATE();
    case 486:
      ACCEPT_TOKEN(sym_optimization_keyword);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 341},
  [2] = {.lex_state = 13},
  [3] = {.lex_state = 13},
  [4] = {.lex_state = 14},
  [5] = {.lex_state = 15},
  [6] = {.lex_state = 15},
  [7] = {.lex_state = 15},
  [8] = {.lex_state = 16},
  [9] = {.lex_state = 17},
  [10] = {.lex_state = 17},
  [11] = {.lex_state = 341},
  [12] = {.lex_state = 341},
  [13] = {.lex_state = 341},
  [14] = {.lex_state = 17},
  [15] = {.lex_state = 341},
  [16] = {.lex_state = 341},
  [17] = {.lex_state = 341},
  [18] = {.lex_state = 341},
  [19] = {.lex_state = 341},
  [20] = {.lex_state = 341},
  [21] = {.lex_state = 341},
  [22] = {.lex_state = 341},
  [23] = {.lex_state = 341},
  [24] = {.lex_state = 341},
  [25] = {.lex_state = 341},
  [26] = {.lex_state = 341},
  [27] = {.lex_state = 341},
  [28] = {.lex_state = 0},
  [29] = {.lex_state = 0},
  [30] = {.lex_state = 0},
  [31] = {.lex_state = 341},
  [32] = {.lex_state = 341},
  [33] = {.lex_state = 0},
  [34] = {.lex_state = 341},
  [35] = {.lex_state = 341},
  [36] = {.lex_state = 341},
  [37] = {.lex_state = 0},
  [38] = {.lex_state = 341},
  [39] = {.lex_state = 341},
  [40] = {.lex_state = 0},
  [41] = {.lex_state = 0},
  [42] = {.lex_state = 341},
  [43] = {.lex_state = 0},
  [44] = {.lex_state = 341},
  [45] = {.lex_state = 341},
  [46] = {.lex_state = 342},
  [47] = {.lex_state = 342},
  [48] = {.lex_state = 342},
  [49] = {.lex_state = 0},
  [50] = {.lex_state = 341},
  [51] = {.lex_state = 341},
  [52] = {.lex_state = 341},
  [53] = {.lex_state = 341},
  [54] = {.lex_state = 341},
  [55] = {.lex_state = 341},
  [56] = {.lex_state = 0},
  [57] = {.lex_state = 341},
  [58] = {.lex_state = 0},
  [59] = {.lex_state = 341},
  [60] = {.lex_state = 341},
  [61] = {.lex_state = 341},
  [62] = {.lex_state = 341},
  [63] = {.lex_state = 341},
  [64] = {.lex_state = 341},
  [65] = {.lex_state = 341},
  [66] = {.lex_state = 341},
  [67] = {.lex_state = 341},
  [68] = {.lex_state = 0},
  [69] = {.lex_state = 341},
  [70] = {.lex_state = 341},
  [71] = {.lex_state = 0},
  [72] = {.lex_state = 341},
  [73] = {.lex_state = 341},
  [74] = {.lex_state = 341},
  [75] = {.lex_state = 0},
  [76] = {.lex_state = 341},
  [77] = {.lex_state = 341},
  [78] = {.lex_state = 341},
  [79] = {.lex_state = 341},
  [80] = {.lex_state = 341},
  [81] = {.lex_state = 341},
  [82] = {.lex_state = 341},
  [83] = {.lex_state = 341},
  [84] = {.lex_state = 341},
  [85] = {.lex_state = 341},
  [86] = {.lex_state = 341},
  [87] = {.lex_state = 341},
  [88] = {.lex_state = 341},
  [89] = {.lex_state = 341},
  [90] = {.lex_state = 341},
  [91] = {.lex_state = 18},
  [92] = {.lex_state = 341},
  [93] = {.lex_state = 0},
  [94] = {.lex_state = 0},
  [95] = {.lex_state = 0},
  [96] = {.lex_state = 341},
  [97] = {.lex_state = 0},
  [98] = {.lex_state = 341},
  [99] = {.lex_state = 0},
  [100] = {.lex_state = 551},
  [101] = {.lex_state = 341},
  [102] = {.lex_state = 0},
  [103] = {.lex_state = 0},
  [104] = {.lex_state = 0},
  [105] = {.lex_state = 0},
  [106] = {.lex_state = 0},
  [107] = {.lex_state = 348},
  [108] = {.lex_state = 0},
  [109] = {.lex_state = 0},
  [110] = {.lex_state = 0},
  [111] = {.lex_state = 0},
  [112] = {(TSStateId)(-1)},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [sym_comment] = STATE(0),
    [ts_builtin_sym_end] = ACTIONS(1),
    [sym_identifier] = ACTIONS(1),
    [anon_sym_POUND] = ACTIONS(3),
    [anon_sym_LBRACE] = ACTIONS(1),
    [anon_sym_RBRACE] = ACTIONS(1),
    [anon_sym_none] = ACTIONS(1),
    [anon_sym_yes] = ACTIONS(1),
    [anon_sym_no] = ACTIONS(1),
    [anon_sym_if_DASHbound] = ACTIONS(1),
    [anon_sym_floating] = ACTIONS(1),
    [anon_sym_urgent] = ACTIONS(1),
    [anon_sym_misc] = ACTIONS(1),
    [anon_sym_loud] = ACTIONS(1),
    [anon_sym_never] = ACTIONS(1),
    [anon_sym_adaptative] = ACTIONS(1),
    [anon_sym_always] = ACTIONS(1),
    [anon_sym_normal] = ACTIONS(1),
    [anon_sym_satellite] = ACTIONS(1),
    [anon_sym_high_DASHlatency] = ACTIONS(1),
    [anon_sym_conservative] = ACTIONS(1),
    [anon_sym_aggressive] = ACTIONS(1),
    [anon_sym_basic] = ACTIONS(1),
    [anon_sym_profile] = ACTIONS(1),
    [anon_sym_COMMA] = ACTIONS(1),
    [anon_sym_tcp_DOTfirst] = ACTIONS(1),
    [anon_sym_tcp_DOTopening] = ACTIONS(1),
    [anon_sym_tcp_DOTestablished] = ACTIONS(1),
    [anon_sym_tcp_DOTclosing] = ACTIONS(1),
    [anon_sym_tcp_DOTfinwait] = ACTIONS(1),
    [anon_sym_tcp_DOTclosed] = ACTIONS(1),
    [anon_sym_tcp_DOTtsdiff] = ACTIONS(1),
    [anon_sym_sctp_DOTopening] = ACTIONS(1),
    [anon_sym_sctp_DOTestablished] = ACTIONS(1),
    [anon_sym_sctp_DOTclosing] = ACTIONS(1),
    [anon_sym_sctp_DOTclosed] = ACTIONS(1),
    [anon_sym_udp_DOTfirst] = ACTIONS(1),
    [anon_sym_udp_DOTsingle] = ACTIONS(1),
    [anon_sym_udp_DOTmultiple] = ACTIONS(1),
    [anon_sym_icmp_DOTfirst] = ACTIONS(1),
    [anon_sym_icmp_DOTerror] = ACTIONS(1),
    [anon_sym_other_DOTfirst] = ACTIONS(1),
    [anon_sym_other_DOTsingle] = ACTIONS(1),
    [anon_sym_other_DOTmultiple] = ACTIONS(1),
    [anon_sym_frag] = ACTIONS(1),
    [anon_sym_interval] = ACTIONS(1),
    [anon_sym_adaptive_DOTstart] = ACTIONS(1),
    [anon_sym_adaptive_DOTend] = ACTIONS(1),
    [anon_sym_src_DOTtrack] = ACTIONS(1),
    [anon_sym_states] = ACTIONS(1),
    [anon_sym_src_DASHnodes] = ACTIONS(1),
    [anon_sym_frags] = ACTIONS(1),
    [anon_sym_table_DASHentries] = ACTIONS(1),
    [anon_sym_SLASH] = ACTIONS(1),
    [anon_sym_LT] = ACTIONS(1),
    [anon_sym_GT] = ACTIONS(1),
    [anon_sym_DQUOTE] = ACTIONS(1),
    [sym_number] = ACTIONS(1),
    [sym_hex_number] = ACTIONS(1),
    [sym_not_operator] = ACTIONS(1),
    [sym_all_keyword] = ACTIONS(1),
    [sym_allow_opts_keyword] = ACTIONS(1),
    [sym_altq_keyword] = ACTIONS(1),
    [sym_anchor_keyword] = ACTIONS(1),
    [sym_antispoof_keyword] = ACTIONS(1),
    [sym_any_keyword] = ACTIONS(1),
    [sym_bandwidth_keyword] = ACTIONS(1),
    [sym_binat_keyword] = ACTIONS(1),
    [sym_binat_anchor_keyword] = ACTIONS(1),
    [sym_bitmask_keyword] = ACTIONS(1),
    [sym_block_keyword] = ACTIONS(1),
    [sym_block_policy_keyword] = ACTIONS(1),
    [sym_bridge_to_keyword] = ACTIONS(1),
    [sym_buckets_keyword] = ACTIONS(1),
    [sym_cbq_keyword] = ACTIONS(1),
    [sym_code_keyword] = ACTIONS(1),
    [sym_codelq_keyword] = ACTIONS(1),
    [sym_debug_keyword] = ACTIONS(1),
    [sym_divert_reply_keyword] = ACTIONS(1),
    [sym_divert_to_keyword] = ACTIONS(1),
    [sym_dnpipe_keyword] = ACTIONS(1),
    [sym_dnqueue_keyword] = ACTIONS(1),
    [sym_drop_keyword] = ACTIONS(1),
    [sym_dup_to_keyword] = ACTIONS(1),
    [sym_ether_keyword] = ACTIONS(1),
    [sym_fail_policy_keyword] = ACTIONS(1),
    [sym_fairq_keyword] = ACTIONS(1),
    [sym_fastroute_keyword] = ACTIONS(1),
    [sym_file_keyword] = ACTIONS(1),
    [sym_fingerprints_keyword] = ACTIONS(1),
    [sym_flags_keyword] = ACTIONS(1),
    [sym_flush_keyword] = ACTIONS(1),
    [sym_for_keyword] = ACTIONS(1),
    [sym_fragment_keyword] = ACTIONS(1),
    [sym_from_keyword] = ACTIONS(1),
    [sym_global_keyword] = ACTIONS(1),
    [sym_group_keyword] = ACTIONS(1),
    [sym_hfsc_keyword] = ACTIONS(1),
    [sym_hogs_keyword] = ACTIONS(1),
    [sym_hostid_keyword] = ACTIONS(1),
    [sym_icmp_type_keyword] = ACTIONS(1),
    [sym_icmp6_type_keyword] = ACTIONS(1),
    [sym_in_keyword] = ACTIONS(1),
    [sym_include_keyword] = ACTIONS(1),
    [sym_inet_keyword] = ACTIONS(1),
    [sym_inet6_keyword] = ACTIONS(1),
    [sym_keep_keyword] = ACTIONS(1),
    [sym_keepcounters_keyword] = ACTIONS(1),
    [sym_l3_keyword] = ACTIONS(1),
    [sym_label_keyword] = ACTIONS(1),
    [sym_limit_keyword] = ACTIONS(1),
    [sym_linkshare_keyword] = ACTIONS(1),
    [sym_load_keyword] = ACTIONS(1),
    [sym_log_keyword] = ACTIONS(1),
    [sym_loginterface_keyword] = ACTIONS(1),
    [sym_map_e_portset_keyword] = ACTIONS(1),
    [sym_match_keyword] = ACTIONS(1),
    [sym_max_keyword] = ACTIONS(1),
    [sym_max_mss_keyword] = ACTIONS(1),
    [sym_max_src_conn_keyword] = ACTIONS(1),
    [sym_max_src_conn_rate_keyword] = ACTIONS(1),
    [sym_max_src_nodes_keyword] = ACTIONS(1),
    [sym_max_src_states_keyword] = ACTIONS(1),
    [sym_min_ttl_keyword] = ACTIONS(1),
    [sym_modulate_keyword] = ACTIONS(1),
    [sym_nat_keyword] = ACTIONS(1),
    [sym_nat_anchor_keyword] = ACTIONS(1),
    [sym_no_df_keyword] = ACTIONS(1),
    [sym_no_route_keyword] = ACTIONS(1),
    [sym_no_sync_keyword] = ACTIONS(1),
    [sym_on_keyword] = ACTIONS(1),
    [sym_optimization_keyword] = ACTIONS(1),
    [sym_os_keyword] = ACTIONS(1),
    [sym_out_keyword] = ACTIONS(1),
    [sym_overload_keyword] = ACTIONS(1),
    [sym_pass_keyword] = ACTIONS(1),
    [sym_pflow_keyword] = ACTIONS(1),
    [sym_port_keyword] = ACTIONS(1),
    [sym_prio_keyword] = ACTIONS(1),
    [sym_priority_keyword] = ACTIONS(1),
    [sym_priq_keyword] = ACTIONS(1),
    [sym_probability_keyword] = ACTIONS(1),
    [sym_proto_keyword] = ACTIONS(1),
    [sym_qlimit_keyword] = ACTIONS(1),
    [sym_queue_keyword] = ACTIONS(1),
    [sym_quick_keyword] = ACTIONS(1),
    [sym_random_keyword] = ACTIONS(1),
    [sym_random_id_keyword] = ACTIONS(1),
    [sym_rdr_keyword] = ACTIONS(1),
    [sym_rdr_anchor_keyword] = ACTIONS(1),
    [sym_realtime_keyword] = ACTIONS(1),
    [sym_reassemble_keyword] = ACTIONS(1),
    [sym_reply_to_keyword] = ACTIONS(1),
    [sym_require_order_keyword] = ACTIONS(1),
    [sym_return_keyword] = ACTIONS(1),
    [sym_return_icmp_keyword] = ACTIONS(1),
    [sym_return_icmp6_keyword] = ACTIONS(1),
    [sym_return_rst_keyword] = ACTIONS(1),
    [sym_ridentifier_keyword] = ACTIONS(1),
    [sym_round_robin_keyword] = ACTIONS(1),
    [sym_route_keyword] = ACTIONS(1),
    [sym_route_to_keyword] = ACTIONS(1),
    [sym_rtable_keyword] = ACTIONS(1),
    [sym_rule_keyword] = ACTIONS(1),
    [sym_scrub_keyword] = ACTIONS(1),
    [sym_self_keyword] = ACTIONS(1),
    [sym_set_keyword] = ACTIONS(1),
    [sym_set_tos_keyword] = ACTIONS(1),
    [sym_skip_keyword] = ACTIONS(1),
    [sym_sloppy_keyword] = ACTIONS(1),
    [sym_source_hash_keyword] = ACTIONS(1),
    [sym_source_track_keyword] = ACTIONS(1),
    [sym_state_keyword] = ACTIONS(1),
    [sym_state_defaults_keyword] = ACTIONS(1),
    [sym_state_policy_keyword] = ACTIONS(1),
    [sym_static_port_keyword] = ACTIONS(1),
    [sym_sticky_address_keyword] = ACTIONS(1),
    [sym_syncookies_keyword] = ACTIONS(1),
    [sym_synproxy_keyword] = ACTIONS(1),
    [sym_table_keyword] = ACTIONS(1),
    [sym_tag_keyword] = ACTIONS(1),
    [sym_tagged_keyword] = ACTIONS(1),
    [sym_target_keyword] = ACTIONS(1),
    [sym_tbrsize_keyword] = ACTIONS(1),
    [sym_timeout_keyword] = ACTIONS(1),
    [sym_to_keyword] = ACTIONS(1),
    [sym_tos_keyword] = ACTIONS(1),
    [sym_ttl_keyword] = ACTIONS(1),
    [sym_upperlimit_keyword] = ACTIONS(1),
    [sym_urpf_failed_keyword] = ACTIONS(1),
    [sym_user_keyword] = ACTIONS(1),
  },
  [1] = {
    [sym_lines] = STATE(111),
    [sym_line] = STATE(55),
    [sym_comment] = STATE(1),
    [sym_option] = STATE(57),
    [aux_sym_lines_repeat1] = STATE(11),
    [ts_builtin_sym_end] = ACTIONS(5),
    [anon_sym_POUND] = ACTIONS(3),
    [sym_set_keyword] = ACTIONS(7),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 15,
    ACTIONS(3), 1,
      anon_sym_POUND,
    ACTIONS(9), 1,
      anon_sym_if_DASHbound,
    ACTIONS(11), 1,
      anon_sym_floating,
    ACTIONS(17), 1,
      sym_max_src_conn_rate_keyword,
    ACTIONS(23), 1,
      sym_overload_keyword,
    ACTIONS(25), 1,
      sym_source_track_keyword,
    STATE(2), 1,
      sym_comment,
    STATE(27), 1,
      sym_state_opt,
    STATE(62), 1,
      sym_state_opt_list,
    STATE(105), 1,
      sym_timeout_type,
    ACTIONS(15), 2,
      sym_max_keyword,
      sym_max_src_conn_keyword,
    ACTIONS(19), 2,
      sym_max_src_nodes_keyword,
      sym_max_src_states_keyword,
    ACTIONS(21), 2,
      sym_no_sync_keyword,
      sym_sloppy_keyword,
    STATE(44), 3,
      sym_timeout_spec,
      sym_floating_keyword,
      sym_if_bound_keyword,
    ACTIONS(13), 24,
      anon_sym_tcp_DOTfirst,
      anon_sym_tcp_DOTopening,
      anon_sym_tcp_DOTestablished,
      anon_sym_tcp_DOTclosing,
      anon_sym_tcp_DOTfinwait,
      anon_sym_tcp_DOTclosed,
      anon_sym_tcp_DOTtsdiff,
      anon_sym_sctp_DOTopening,
      anon_sym_sctp_DOTestablished,
      anon_sym_sctp_DOTclosing,
      anon_sym_sctp_DOTclosed,
      anon_sym_udp_DOTfirst,
      anon_sym_udp_DOTsingle,
      anon_sym_udp_DOTmultiple,
      anon_sym_icmp_DOTfirst,
      anon_sym_icmp_DOTerror,
      anon_sym_other_DOTfirst,
      anon_sym_other_DOTsingle,
      anon_sym_other_DOTmultiple,
      anon_sym_frag,
      anon_sym_interval,
      anon_sym_adaptive_DOTstart,
      anon_sym_adaptive_DOTend,
      anon_sym_src_DOTtrack,
  [74] = 14,
    ACTIONS(3), 1,
      anon_sym_POUND,
    ACTIONS(9), 1,
      anon_sym_if_DASHbound,
    ACTIONS(11), 1,
      anon_sym_floating,
    ACTIONS(17), 1,
      sym_max_src_conn_rate_keyword,
    ACTIONS(23), 1,
      sym_overload_keyword,
    ACTIONS(25), 1,
      sym_source_track_keyword,
    STATE(3), 1,
      sym_comment,
    STATE(36), 1,
      sym_state_opt,
    STATE(105), 1,
      sym_timeout_type,
    ACTIONS(15), 2,
      sym_max_keyword,
      sym_max_src_conn_keyword,
    ACTIONS(19), 2,
      sym_max_src_nodes_keyword,
      sym_max_src_states_keyword,
    ACTIONS(21), 2,
      sym_no_sync_keyword,
      sym_sloppy_keyword,
    STATE(44), 3,
      sym_timeout_spec,
      sym_floating_keyword,
      sym_if_bound_keyword,
    ACTIONS(13), 24,
      anon_sym_tcp_DOTfirst,
      anon_sym_tcp_DOTopening,
      anon_sym_tcp_DOTestablished,
      anon_sym_tcp_DOTclosing,
      anon_sym_tcp_DOTfinwait,
      anon_sym_tcp_DOTclosed,
      anon_sym_tcp_DOTtsdiff,
      anon_sym_sctp_DOTopening,
      anon_sym_sctp_DOTestablished,
      anon_sym_sctp_DOTclosing,
      anon_sym_sctp_DOTclosed,
      anon_sym_udp_DOTfirst,
      anon_sym_udp_DOTsingle,
      anon_sym_udp_DOTmultiple,
      anon_sym_icmp_DOTfirst,
      anon_sym_icmp_DOTerror,
      anon_sym_other_DOTfirst,
      anon_sym_other_DOTsingle,
      anon_sym_other_DOTmultiple,
      anon_sym_frag,
      anon_sym_interval,
      anon_sym_adaptive_DOTstart,
      anon_sym_adaptive_DOTend,
      anon_sym_src_DOTtrack,
  [145] = 25,
    ACTIONS(3), 1,
      anon_sym_POUND,
    ACTIONS(27), 1,
      sym_block_policy_keyword,
    ACTIONS(29), 1,
      sym_debug_keyword,
    ACTIONS(31), 1,
      sym_fail_policy_keyword,
    ACTIONS(33), 1,
      sym_fingerprints_keyword,
    ACTIONS(35), 1,
      sym_hostid_keyword,
    ACTIONS(37), 1,
      sym_keepcounters_keyword,
    ACTIONS(39), 1,
      sym_limit_keyword,
    ACTIONS(41), 1,
      sym_loginterface_keyword,
    ACTIONS(43), 1,
      sym_optimization_keyword,
    ACTIONS(45), 1,
      sym_reassemble_keyword,
    ACTIONS(47), 1,
      sym_require_order_keyword,
    ACTIONS(49), 1,
      sym_ruleset_optimization_keyword,
    ACTIONS(51), 1,
      sym_skip_keyword,
    ACTIONS(53), 1,
      sym_state_defaults_keyword,
    ACTIONS(55), 1,
      sym_state_policy_keyword,
    ACTIONS(57), 1,
      sym_syncookies_keyword,
    ACTIONS(59), 1,
      sym_timeout_keyword,
    STATE(4), 1,
      sym_comment,
    STATE(50), 1,
      sym__ruleset_optimization_option,
    STATE(84), 1,
      sym__fingerprints_option,
    STATE(86), 1,
      sym__hostid_option,
    STATE(89), 1,
      sym__loginterface_option,
    STATE(90), 1,
      sym__optimization_option,
    STATE(92), 12,
      sym__reassemble_option,
      sym__timeout_option,
      sym__limit_option,
      sym__block_policy_option,
      sym__fail_policy_option,
      sym__require_order_option,
      sym__state_policy_option,
      sym__debug_option,
      sym__skip_option,
      sym__state_defaults_option,
      sym__keep_counters_option,
      sym__syncookies_option,
  [232] = 6,
    ACTIONS(3), 1,
      anon_sym_POUND,
    ACTIONS(61), 1,
      anon_sym_LBRACE,
    STATE(5), 1,
      sym_comment,
    STATE(67), 1,
      sym_timeout_spec,
    STATE(105), 1,
      sym_timeout_type,
    ACTIONS(13), 24,
      anon_sym_tcp_DOTfirst,
      anon_sym_tcp_DOTopening,
      anon_sym_tcp_DOTestablished,
      anon_sym_tcp_DOTclosing,
      anon_sym_tcp_DOTfinwait,
      anon_sym_tcp_DOTclosed,
      anon_sym_tcp_DOTtsdiff,
      anon_sym_sctp_DOTopening,
      anon_sym_sctp_DOTestablished,
      anon_sym_sctp_DOTclosing,
      anon_sym_sctp_DOTclosed,
      anon_sym_udp_DOTfirst,
      anon_sym_udp_DOTsingle,
      anon_sym_udp_DOTmultiple,
      anon_sym_icmp_DOTfirst,
      anon_sym_icmp_DOTerror,
      anon_sym_other_DOTfirst,
      anon_sym_other_DOTsingle,
      anon_sym_other_DOTmultiple,
      anon_sym_frag,
      anon_sym_interval,
      anon_sym_adaptive_DOTstart,
      anon_sym_adaptive_DOTend,
      anon_sym_src_DOTtrack,
  [274] = 6,
    ACTIONS(3), 1,
      anon_sym_POUND,
    STATE(6), 1,
      sym_comment,
    STATE(29), 1,
      sym_timeout_spec,
    STATE(97), 1,
      sym_timeout_list,
    STATE(105), 1,
      sym_timeout_type,
    ACTIONS(13), 24,
      anon_sym_tcp_DOTfirst,
      anon_sym_tcp_DOTopening,
      anon_sym_tcp_DOTestablished,
      anon_sym_tcp_DOTclosing,
      anon_sym_tcp_DOTfinwait,
      anon_sym_tcp_DOTclosed,
      anon_sym_tcp_DOTtsdiff,
      anon_sym_sctp_DOTopening,
      anon_sym_sctp_DOTestablished,
      anon_sym_sctp_DOTclosing,
      anon_sym_sctp_DOTclosed,
      anon_sym_udp_DOTfirst,
      anon_sym_udp_DOTsingle,
      anon_sym_udp_DOTmultiple,
      anon_sym_icmp_DOTfirst,
      anon_sym_icmp_DOTerror,
      anon_sym_other_DOTfirst,
      anon_sym_other_DOTsingle,
      anon_sym_other_DOTmultiple,
      anon_sym_frag,
      anon_sym_interval,
      anon_sym_adaptive_DOTstart,
      anon_sym_adaptive_DOTend,
      anon_sym_src_DOTtrack,
  [316] = 5,
    ACTIONS(3), 1,
      anon_sym_POUND,
    STATE(7), 1,
      sym_comment,
    STATE(58), 1,
      sym_timeout_spec,
    STATE(105), 1,
      sym_timeout_type,
    ACTIONS(13), 24,
      anon_sym_tcp_DOTfirst,
      anon_sym_tcp_DOTopening,
      anon_sym_tcp_DOTestablished,
      anon_sym_tcp_DOTclosing,
      anon_sym_tcp_DOTfinwait,
      anon_sym_tcp_DOTclosed,
      anon_sym_tcp_DOTtsdiff,
      anon_sym_sctp_DOTopening,
      anon_sym_sctp_DOTestablished,
      anon_sym_sctp_DOTclosing,
      anon_sym_sctp_DOTclosed,
      anon_sym_udp_DOTfirst,
      anon_sym_udp_DOTsingle,
      anon_sym_udp_DOTmultiple,
      anon_sym_icmp_DOTfirst,
      anon_sym_icmp_DOTerror,
      anon_sym_other_DOTfirst,
      anon_sym_other_DOTsingle,
      anon_sym_other_DOTmultiple,
      anon_sym_frag,
      anon_sym_interval,
      anon_sym_adaptive_DOTstart,
      anon_sym_adaptive_DOTend,
      anon_sym_src_DOTtrack,
  [355] = 4,
    ACTIONS(3), 1,
      anon_sym_POUND,
    STATE(8), 1,
      sym_comment,
    STATE(82), 1,
      sym_optimization_hint,
    ACTIONS(63), 5,
      anon_sym_normal,
      anon_sym_satellite,
      anon_sym_high_DASHlatency,
      anon_sym_conservative,
      anon_sym_aggressive,
  [372] = 5,
    ACTIONS(3), 1,
      anon_sym_POUND,
    STATE(9), 1,
      sym_comment,
    STATE(40), 1,
      sym_limit_spec,
    STATE(103), 1,
      sym_limit_list,
    ACTIONS(65), 4,
      anon_sym_states,
      anon_sym_src_DASHnodes,
      anon_sym_frags,
      anon_sym_table_DASHentries,
  [391] = 5,
    ACTIONS(3), 1,
      anon_sym_POUND,
    ACTIONS(67), 1,
      anon_sym_LBRACE,
    STATE(10), 1,
      sym_comment,
    STATE(70), 1,
      sym_limit_spec,
    ACTIONS(65), 4,
      anon_sym_states,
      anon_sym_src_DASHnodes,
      anon_sym_frags,
      anon_sym_table_DASHentries,
  [410] = 7,
    ACTIONS(3), 1,
      anon_sym_POUND,
    ACTIONS(7), 1,
      sym_set_keyword,
    ACTIONS(69), 1,
      ts_builtin_sym_end,
    STATE(11), 1,
      sym_comment,
    STATE(13), 1,
      aux_sym_lines_repeat1,
    STATE(55), 1,
      sym_line,
    STATE(57), 1,
      sym_option,
  [432] = 7,
    ACTIONS(3), 1,
      anon_sym_POUND,
    ACTIONS(71), 1,
      sym_identifier,
    ACTIONS(73), 1,
      anon_sym_LBRACE,
    ACTIONS(75), 1,
      sym_not_operator,
    STATE(12), 1,
      sym_comment,
    STATE(76), 1,
      sym_ifspec,
    STATE(77), 1,
      sym_interface,
  [454] = 6,
    ACTIONS(3), 1,
      anon_sym_POUND,
    ACTIONS(77), 1,
      ts_builtin_sym_end,
    ACTIONS(79), 1,
      sym_set_keyword,
    STATE(55), 1,
      sym_line,
    STATE(57), 1,
      sym_option,
    STATE(13), 2,
      sym_comment,
      aux_sym_lines_repeat1,
  [474] = 4,
    ACTIONS(3), 1,
      anon_sym_POUND,
    STATE(14), 1,
      sym_comment,
    STATE(75), 1,
      sym_limit_spec,
    ACTIONS(65), 4,
      anon_sym_states,
      anon_sym_src_DASHnodes,
      anon_sym_frags,
      anon_sym_table_DASHentries,
  [490] = 4,
    ACTIONS(3), 1,
      anon_sym_POUND,
    STATE(15), 1,
      sym_comment,
    ACTIONS(84), 2,
      sym_global_keyword,
      sym_rule_keyword,
    ACTIONS(82), 3,
      ts_builtin_sym_end,
      anon_sym_COMMA,
      sym_set_keyword,
  [506] = 3,
    ACTIONS(3), 1,
      anon_sym_POUND,
    STATE(16), 1,
      sym_comment,
    ACTIONS(86), 4,
      ts_builtin_sym_end,
      anon_sym_RBRACE,
      anon_sym_COMMA,
      sym_set_keyword,
  [519] = 6,
    ACTIONS(3), 1,
      anon_sym_POUND,
    ACTIONS(71), 1,
      sym_identifier,
    ACTIONS(75), 1,
      sym_not_operator,
    STATE(17), 1,
      sym_comment,
    STATE(33), 1,
      sym_interface,
    STATE(93), 1,
      sym_interface_list,
  [538] = 3,
    ACTIONS(3), 1,
      anon_sym_POUND,
    STATE(18), 1,
      sym_comment,
    ACTIONS(88), 4,
      ts_builtin_sym_end,
      anon_sym_RBRACE,
      anon_sym_COMMA,
      sym_set_keyword,
  [551] = 4,
    ACTIONS(3), 1,
      anon_sym_POUND,
    ACTIONS(92), 1,
      anon_sym_COMMA,
    ACTIONS(90), 2,
      ts_builtin_sym_end,
      sym_set_keyword,
    STATE(19), 2,
      sym_comment,
      aux_sym_state_opt_list_repeat1,
  [566] = 3,
    ACTIONS(3), 1,
      anon_sym_POUND,
    STATE(20), 1,
      sym_comment,
    ACTIONS(95), 4,
      anon_sym_none,
      anon_sym_urgent,
      anon_sym_misc,
      anon_sym_loud,
  [579] = 5,
    ACTIONS(3), 1,
      anon_sym_POUND,
    ACTIONS(97), 1,
      anon_sym_yes,
    ACTIONS(99), 1,
      anon_sym_no,
    STATE(21), 1,
      sym_comment,
    STATE(48), 2,
      sym_no_keyword,
      sym_yes_keyword,
  [596] = 3,
    ACTIONS(3), 1,
      anon_sym_POUND,
    STATE(22), 1,
      sym_comment,
    ACTIONS(101), 4,
      ts_builtin_sym_end,
      anon_sym_RBRACE,
      anon_sym_COMMA,
      sym_set_keyword,
  [609] = 4,
    ACTIONS(3), 1,
      anon_sym_POUND,
    STATE(23), 1,
      sym_comment,
    STATE(54), 1,
      sym_ruleset_optimizer,
    ACTIONS(103), 3,
      anon_sym_none,
      anon_sym_basic,
      anon_sym_profile,
  [624] = 3,
    ACTIONS(3), 1,
      anon_sym_POUND,
    STATE(24), 1,
      sym_comment,
    ACTIONS(105), 4,
      ts_builtin_sym_end,
      anon_sym_RBRACE,
      anon_sym_COMMA,
      sym_set_keyword,
  [637] = 5,
    ACTIONS(3), 1,
      anon_sym_POUND,
    ACTIONS(109), 1,
      anon_sym_COMMA,
    STATE(19), 1,
      aux_sym_state_opt_list_repeat1,
    STATE(25), 1,
      sym_comment,
    ACTIONS(107), 2,
      ts_builtin_sym_end,
      sym_set_keyword,
  [654] = 4,
    ACTIONS(3), 1,
      anon_sym_POUND,
    ACTIONS(113), 1,
      sym_flush_keyword,
    STATE(26), 1,
      sym_comment,
    ACTIONS(111), 3,
      ts_builtin_sym_end,
      anon_sym_COMMA,
      sym_set_keyword,
  [669] = 5,
    ACTIONS(3), 1,
      anon_sym_POUND,
    ACTIONS(109), 1,
      anon_sym_COMMA,
    STATE(25), 1,
      aux_sym_state_opt_list_repeat1,
    STATE(27), 1,
      sym_comment,
    ACTIONS(115), 2,
      ts_builtin_sym_end,
      sym_set_keyword,
  [686] = 4,
    ACTIONS(3), 1,
      anon_sym_POUND,
    ACTIONS(117), 1,
      anon_sym_RBRACE,
    ACTIONS(119), 1,
      anon_sym_COMMA,
    STATE(28), 2,
      sym_comment,
      aux_sym_limit_list_repeat1,
  [700] = 5,
    ACTIONS(3), 1,
      anon_sym_POUND,
    ACTIONS(122), 1,
      anon_sym_RBRACE,
    ACTIONS(124), 1,
      anon_sym_COMMA,
    STATE(29), 1,
      sym_comment,
    STATE(37), 1,
      aux_sym_timeout_list_repeat1,
  [716] = 5,
    ACTIONS(3), 1,
      anon_sym_POUND,
    ACTIONS(126), 1,
      anon_sym_RBRACE,
    ACTIONS(128), 1,
      anon_sym_COMMA,
    STATE(28), 1,
      aux_sym_limit_list_repeat1,
    STATE(30), 1,
      sym_comment,
  [732] = 3,
    ACTIONS(3), 1,
      anon_sym_POUND,
    STATE(31), 1,
      sym_comment,
    ACTIONS(130), 3,
      ts_builtin_sym_end,
      anon_sym_COMMA,
      sym_set_keyword,
  [744] = 3,
    ACTIONS(3), 1,
      anon_sym_POUND,
    STATE(32), 1,
      sym_comment,
    ACTIONS(132), 3,
      anon_sym_never,
      anon_sym_adaptative,
      anon_sym_always,
  [756] = 5,
    ACTIONS(3), 1,
      anon_sym_POUND,
    ACTIONS(134), 1,
      anon_sym_RBRACE,
    ACTIONS(136), 1,
      anon_sym_COMMA,
    STATE(33), 1,
      sym_comment,
    STATE(41), 1,
      aux_sym_interface_list_repeat1,
  [772] = 3,
    ACTIONS(3), 1,
      anon_sym_POUND,
    STATE(34), 1,
      sym_comment,
    ACTIONS(138), 3,
      ts_builtin_sym_end,
      anon_sym_COMMA,
      sym_set_keyword,
  [784] = 3,
    ACTIONS(3), 1,
      anon_sym_POUND,
    STATE(35), 1,
      sym_comment,
    ACTIONS(140), 3,
      ts_builtin_sym_end,
      anon_sym_COMMA,
      sym_set_keyword,
  [796] = 3,
    ACTIONS(3), 1,
      anon_sym_POUND,
    STATE(36), 1,
      sym_comment,
    ACTIONS(90), 3,
      ts_builtin_sym_end,
      anon_sym_COMMA,
      sym_set_keyword,
  [808] = 5,
    ACTIONS(3), 1,
      anon_sym_POUND,
    ACTIONS(124), 1,
      anon_sym_COMMA,
    ACTIONS(142), 1,
      anon_sym_RBRACE,
    STATE(37), 1,
      sym_comment,
    STATE(43), 1,
      aux_sym_timeout_list_repeat1,
  [824] = 3,
    ACTIONS(3), 1,
      anon_sym_POUND,
    STATE(38), 1,
      sym_comment,
    ACTIONS(144), 3,
      ts_builtin_sym_end,
      anon_sym_COMMA,
      sym_set_keyword,
  [836] = 5,
    ACTIONS(3), 1,
      anon_sym_POUND,
    ACTIONS(71), 1,
      sym_identifier,
    ACTIONS(75), 1,
      sym_not_operator,
    STATE(39), 1,
      sym_comment,
    STATE(56), 1,
      sym_interface,
  [852] = 5,
    ACTIONS(3), 1,
      anon_sym_POUND,
    ACTIONS(128), 1,
      anon_sym_COMMA,
    ACTIONS(146), 1,
      anon_sym_RBRACE,
    STATE(30), 1,
      aux_sym_limit_list_repeat1,
    STATE(40), 1,
      sym_comment,
  [868] = 5,
    ACTIONS(3), 1,
      anon_sym_POUND,
    ACTIONS(136), 1,
      anon_sym_COMMA,
    ACTIONS(148), 1,
      anon_sym_RBRACE,
    STATE(41), 1,
      sym_comment,
    STATE(49), 1,
      aux_sym_interface_list_repeat1,
  [884] = 3,
    ACTIONS(3), 1,
      anon_sym_POUND,
    STATE(42), 1,
      sym_comment,
    ACTIONS(150), 3,
      ts_builtin_sym_end,
      anon_sym_COMMA,
      sym_set_keyword,
  [896] = 4,
    ACTIONS(3), 1,
      anon_sym_POUND,
    ACTIONS(152), 1,
      anon_sym_RBRACE,
    ACTIONS(154), 1,
      anon_sym_COMMA,
    STATE(43), 2,
      sym_comment,
      aux_sym_timeout_list_repeat1,
  [910] = 3,
    ACTIONS(3), 1,
      anon_sym_POUND,
    STATE(44), 1,
      sym_comment,
    ACTIONS(82), 3,
      ts_builtin_sym_end,
      anon_sym_COMMA,
      sym_set_keyword,
  [922] = 3,
    ACTIONS(3), 1,
      anon_sym_POUND,
    STATE(45), 1,
      sym_comment,
    ACTIONS(157), 3,
      ts_builtin_sym_end,
      anon_sym_COMMA,
      sym_set_keyword,
  [934] = 3,
    ACTIONS(3), 1,
      anon_sym_POUND,
    STATE(46), 1,
      sym_comment,
    ACTIONS(159), 3,
      ts_builtin_sym_end,
      sym_no_df_keyword,
      sym_set_keyword,
  [946] = 3,
    ACTIONS(3), 1,
      anon_sym_POUND,
    STATE(47), 1,
      sym_comment,
    ACTIONS(161), 3,
      ts_builtin_sym_end,
      sym_no_df_keyword,
      sym_set_keyword,
  [958] = 4,
    ACTIONS(3), 1,
      anon_sym_POUND,
    ACTIONS(165), 1,
      sym_no_df_keyword,
    STATE(48), 1,
      sym_comment,
    ACTIONS(163), 2,
      ts_builtin_sym_end,
      sym_set_keyword,
  [972] = 4,
    ACTIONS(3), 1,
      anon_sym_POUND,
    ACTIONS(167), 1,
      anon_sym_RBRACE,
    ACTIONS(169), 1,
      anon_sym_COMMA,
    STATE(49), 2,
      sym_comment,
      aux_sym_interface_list_repeat1,
  [986] = 3,
    ACTIONS(3), 1,
      anon_sym_POUND,
    STATE(50), 1,
      sym_comment,
    ACTIONS(172), 2,
      ts_builtin_sym_end,
      sym_set_keyword,
  [997] = 3,
    ACTIONS(3), 1,
      anon_sym_POUND,
    STATE(51), 1,
      sym_comment,
    ACTIONS(174), 2,
      ts_builtin_sym_end,
      sym_set_keyword,
  [1008] = 3,
    ACTIONS(3), 1,
      anon_sym_POUND,
    STATE(52), 1,
      sym_comment,
    ACTIONS(176), 2,
      ts_builtin_sym_end,
      sym_set_keyword,
  [1019] = 3,
    ACTIONS(3), 1,
      anon_sym_POUND,
    STATE(53), 1,
      sym_comment,
    ACTIONS(178), 2,
      ts_builtin_sym_end,
      sym_set_keyword,
  [1030] = 3,
    ACTIONS(3), 1,
      anon_sym_POUND,
    STATE(54), 1,
      sym_comment,
    ACTIONS(180), 2,
      ts_builtin_sym_end,
      sym_set_keyword,
  [1041] = 3,
    ACTIONS(3), 1,
      anon_sym_POUND,
    STATE(55), 1,
      sym_comment,
    ACTIONS(182), 2,
      ts_builtin_sym_end,
      sym_set_keyword,
  [1052] = 3,
    ACTIONS(3), 1,
      anon_sym_POUND,
    STATE(56), 1,
      sym_comment,
    ACTIONS(167), 2,
      anon_sym_RBRACE,
      anon_sym_COMMA,
  [1063] = 3,
    ACTIONS(3), 1,
      anon_sym_POUND,
    STATE(57), 1,
      sym_comment,
    ACTIONS(184), 2,
      ts_builtin_sym_end,
      sym_set_keyword,
  [1074] = 3,
    ACTIONS(3), 1,
      anon_sym_POUND,
    STATE(58), 1,
      sym_comment,
    ACTIONS(152), 2,
      anon_sym_RBRACE,
      anon_sym_COMMA,
  [1085] = 3,
    ACTIONS(3), 1,
      anon_sym_POUND,
    STATE(59), 1,
      sym_comment,
    ACTIONS(186), 2,
      sym_drop_keyword,
      sym_return_keyword,
  [1096] = 3,
    ACTIONS(3), 1,
      anon_sym_POUND,
    STATE(60), 1,
      sym_comment,
    ACTIONS(188), 2,
      ts_builtin_sym_end,
      sym_set_keyword,
  [1107] = 3,
    ACTIONS(3), 1,
      anon_sym_POUND,
    STATE(61), 1,
      sym_comment,
    ACTIONS(190), 2,
      sym_drop_keyword,
      sym_return_keyword,
  [1118] = 3,
    ACTIONS(3), 1,
      anon_sym_POUND,
    STATE(62), 1,
      sym_comment,
    ACTIONS(192), 2,
      ts_builtin_sym_end,
      sym_set_keyword,
  [1129] = 3,
    ACTIONS(3), 1,
      anon_sym_POUND,
    STATE(63), 1,
      sym_comment,
    ACTIONS(194), 2,
      ts_builtin_sym_end,
      sym_set_keyword,
  [1140] = 3,
    ACTIONS(3), 1,
      anon_sym_POUND,
    STATE(64), 1,
      sym_comment,
    ACTIONS(196), 2,
      ts_builtin_sym_end,
      sym_set_keyword,
  [1151] = 3,
    ACTIONS(3), 1,
      anon_sym_POUND,
    STATE(65), 1,
      sym_comment,
    ACTIONS(198), 2,
      ts_builtin_sym_end,
      sym_set_keyword,
  [1162] = 3,
    ACTIONS(3), 1,
      anon_sym_POUND,
    STATE(66), 1,
      sym_comment,
    ACTIONS(200), 2,
      ts_builtin_sym_end,
      sym_set_keyword,
  [1173] = 3,
    ACTIONS(3), 1,
      anon_sym_POUND,
    STATE(67), 1,
      sym_comment,
    ACTIONS(202), 2,
      ts_builtin_sym_end,
      sym_set_keyword,
  [1184] = 4,
    ACTIONS(3), 1,
      anon_sym_POUND,
    ACTIONS(204), 1,
      anon_sym_DQUOTE,
    STATE(68), 1,
      sym_comment,
    STATE(74), 1,
      sym_string,
  [1197] = 3,
    ACTIONS(3), 1,
      anon_sym_POUND,
    STATE(69), 1,
      sym_comment,
    ACTIONS(206), 2,
      ts_builtin_sym_end,
      sym_set_keyword,
  [1208] = 3,
    ACTIONS(3), 1,
      anon_sym_POUND,
    STATE(70), 1,
      sym_comment,
    ACTIONS(208), 2,
      ts_builtin_sym_end,
      sym_set_keyword,
  [1219] = 4,
    ACTIONS(3), 1,
      anon_sym_POUND,
    ACTIONS(210), 1,
      sym_number,
    ACTIONS(212), 1,
      sym_hex_number,
    STATE(71), 1,
      sym_comment,
  [1232] = 3,
    ACTIONS(3), 1,
      anon_sym_POUND,
    STATE(72), 1,
      sym_comment,
    ACTIONS(214), 2,
      ts_builtin_sym_end,
      sym_set_keyword,
  [1243] = 3,
    ACTIONS(3), 1,
      anon_sym_POUND,
    STATE(73), 1,
      sym_comment,
    ACTIONS(216), 2,
      ts_builtin_sym_end,
      sym_set_keyword,
  [1254] = 3,
    ACTIONS(3), 1,
      anon_sym_POUND,
    STATE(74), 1,
      sym_comment,
    ACTIONS(218), 2,
      ts_builtin_sym_end,
      sym_set_keyword,
  [1265] = 3,
    ACTIONS(3), 1,
      anon_sym_POUND,
    STATE(75), 1,
      sym_comment,
    ACTIONS(117), 2,
      anon_sym_RBRACE,
      anon_sym_COMMA,
  [1276] = 3,
    ACTIONS(3), 1,
      anon_sym_POUND,
    STATE(76), 1,
      sym_comment,
    ACTIONS(220), 2,
      ts_builtin_sym_end,
      sym_set_keyword,
  [1287] = 3,
    ACTIONS(3), 1,
      anon_sym_POUND,
    STATE(77), 1,
      sym_comment,
    ACTIONS(222), 2,
      ts_builtin_sym_end,
      sym_set_keyword,
  [1298] = 3,
    ACTIONS(3), 1,
      anon_sym_POUND,
    STATE(78), 1,
      sym_comment,
    ACTIONS(224), 2,
      ts_builtin_sym_end,
      sym_set_keyword,
  [1309] = 4,
    ACTIONS(3), 1,
      anon_sym_POUND,
    ACTIONS(226), 1,
      sym_identifier,
    ACTIONS(228), 1,
      anon_sym_none,
    STATE(79), 1,
      sym_comment,
  [1322] = 3,
    ACTIONS(3), 1,
      anon_sym_POUND,
    STATE(80), 1,
      sym_comment,
    ACTIONS(230), 2,
      ts_builtin_sym_end,
      sym_set_keyword,
  [1333] = 3,
    ACTIONS(3), 1,
      anon_sym_POUND,
    STATE(81), 1,
      sym_comment,
    ACTIONS(232), 2,
      ts_builtin_sym_end,
      sym_set_keyword,
  [1344] = 3,
    ACTIONS(3), 1,
      anon_sym_POUND,
    STATE(82), 1,
      sym_comment,
    ACTIONS(234), 2,
      ts_builtin_sym_end,
      sym_set_keyword,
  [1355] = 3,
    ACTIONS(3), 1,
      anon_sym_POUND,
    STATE(83), 1,
      sym_comment,
    ACTIONS(236), 2,
      ts_builtin_sym_end,
      sym_set_keyword,
  [1366] = 3,
    ACTIONS(3), 1,
      anon_sym_POUND,
    STATE(84), 1,
      sym_comment,
    ACTIONS(238), 2,
      ts_builtin_sym_end,
      sym_set_keyword,
  [1377] = 3,
    ACTIONS(3), 1,
      anon_sym_POUND,
    STATE(85), 1,
      sym_comment,
    ACTIONS(240), 2,
      anon_sym_yes,
      anon_sym_no,
  [1388] = 3,
    ACTIONS(3), 1,
      anon_sym_POUND,
    STATE(86), 1,
      sym_comment,
    ACTIONS(242), 2,
      ts_builtin_sym_end,
      sym_set_keyword,
  [1399] = 3,
    ACTIONS(3), 1,
      anon_sym_POUND,
    STATE(87), 1,
      sym_comment,
    ACTIONS(244), 2,
      ts_builtin_sym_end,
      sym_set_keyword,
  [1410] = 3,
    ACTIONS(3), 1,
      anon_sym_POUND,
    STATE(88), 1,
      sym_comment,
    ACTIONS(246), 2,
      ts_builtin_sym_end,
      sym_set_keyword,
  [1421] = 3,
    ACTIONS(3), 1,
      anon_sym_POUND,
    STATE(89), 1,
      sym_comment,
    ACTIONS(248), 2,
      ts_builtin_sym_end,
      sym_set_keyword,
  [1432] = 3,
    ACTIONS(3), 1,
      anon_sym_POUND,
    STATE(90), 1,
      sym_comment,
    ACTIONS(250), 2,
      ts_builtin_sym_end,
      sym_set_keyword,
  [1443] = 3,
    ACTIONS(3), 1,
      anon_sym_POUND,
    STATE(91), 1,
      sym_comment,
    ACTIONS(252), 2,
      anon_sym_if_DASHbound,
      anon_sym_floating,
  [1454] = 3,
    ACTIONS(3), 1,
      anon_sym_POUND,
    STATE(92), 1,
      sym_comment,
    ACTIONS(254), 2,
      ts_builtin_sym_end,
      sym_set_keyword,
  [1465] = 3,
    ACTIONS(3), 1,
      anon_sym_POUND,
    ACTIONS(256), 1,
      anon_sym_RBRACE,
    STATE(93), 1,
      sym_comment,
  [1475] = 3,
    ACTIONS(3), 1,
      anon_sym_POUND,
    ACTIONS(258), 1,
      sym_number,
    STATE(94), 1,
      sym_comment,
  [1485] = 3,
    ACTIONS(3), 1,
      anon_sym_POUND,
    ACTIONS(260), 1,
      anon_sym_GT,
    STATE(95), 1,
      sym_comment,
  [1495] = 3,
    ACTIONS(3), 1,
      anon_sym_POUND,
    ACTIONS(262), 1,
      sym_on_keyword,
    STATE(96), 1,
      sym_comment,
  [1505] = 3,
    ACTIONS(3), 1,
      anon_sym_POUND,
    ACTIONS(264), 1,
      anon_sym_RBRACE,
    STATE(97), 1,
      sym_comment,
  [1515] = 3,
    ACTIONS(3), 1,
      anon_sym_POUND,
    ACTIONS(266), 1,
      sym_identifier,
    STATE(98), 1,
      sym_comment,
  [1525] = 3,
    ACTIONS(3), 1,
      anon_sym_POUND,
    ACTIONS(268), 1,
      anon_sym_SLASH,
    STATE(99), 1,
      sym_comment,
  [1535] = 3,
    ACTIONS(270), 1,
      anon_sym_POUND,
    ACTIONS(272), 1,
      aux_sym_string_token1,
    STATE(100), 1,
      sym_comment,
  [1545] = 3,
    ACTIONS(3), 1,
      anon_sym_POUND,
    ACTIONS(274), 1,
      sym_identifier,
    STATE(101), 1,
      sym_comment,
  [1555] = 3,
    ACTIONS(3), 1,
      anon_sym_POUND,
    ACTIONS(276), 1,
      sym_number,
    STATE(102), 1,
      sym_comment,
  [1565] = 3,
    ACTIONS(3), 1,
      anon_sym_POUND,
    ACTIONS(278), 1,
      anon_sym_RBRACE,
    STATE(103), 1,
      sym_comment,
  [1575] = 3,
    ACTIONS(3), 1,
      anon_sym_POUND,
    ACTIONS(280), 1,
      anon_sym_DQUOTE,
    STATE(104), 1,
      sym_comment,
  [1585] = 3,
    ACTIONS(3), 1,
      anon_sym_POUND,
    ACTIONS(282), 1,
      sym_number,
    STATE(105), 1,
      sym_comment,
  [1595] = 3,
    ACTIONS(3), 1,
      anon_sym_POUND,
    ACTIONS(284), 1,
      anon_sym_LT,
    STATE(106), 1,
      sym_comment,
  [1605] = 3,
    ACTIONS(270), 1,
      anon_sym_POUND,
    ACTIONS(286), 1,
      aux_sym_comment_token1,
    STATE(107), 1,
      sym_comment,
  [1615] = 3,
    ACTIONS(3), 1,
      anon_sym_POUND,
    ACTIONS(288), 1,
      sym_number,
    STATE(108), 1,
      sym_comment,
  [1625] = 3,
    ACTIONS(3), 1,
      anon_sym_POUND,
    ACTIONS(290), 1,
      sym_number,
    STATE(109), 1,
      sym_comment,
  [1635] = 3,
    ACTIONS(3), 1,
      anon_sym_POUND,
    ACTIONS(292), 1,
      sym_number,
    STATE(110), 1,
      sym_comment,
  [1645] = 3,
    ACTIONS(3), 1,
      anon_sym_POUND,
    ACTIONS(294), 1,
      ts_builtin_sym_end,
    STATE(111), 1,
      sym_comment,
  [1655] = 1,
    ACTIONS(296), 1,
      ts_builtin_sym_end,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 74,
  [SMALL_STATE(4)] = 145,
  [SMALL_STATE(5)] = 232,
  [SMALL_STATE(6)] = 274,
  [SMALL_STATE(7)] = 316,
  [SMALL_STATE(8)] = 355,
  [SMALL_STATE(9)] = 372,
  [SMALL_STATE(10)] = 391,
  [SMALL_STATE(11)] = 410,
  [SMALL_STATE(12)] = 432,
  [SMALL_STATE(13)] = 454,
  [SMALL_STATE(14)] = 474,
  [SMALL_STATE(15)] = 490,
  [SMALL_STATE(16)] = 506,
  [SMALL_STATE(17)] = 519,
  [SMALL_STATE(18)] = 538,
  [SMALL_STATE(19)] = 551,
  [SMALL_STATE(20)] = 566,
  [SMALL_STATE(21)] = 579,
  [SMALL_STATE(22)] = 596,
  [SMALL_STATE(23)] = 609,
  [SMALL_STATE(24)] = 624,
  [SMALL_STATE(25)] = 637,
  [SMALL_STATE(26)] = 654,
  [SMALL_STATE(27)] = 669,
  [SMALL_STATE(28)] = 686,
  [SMALL_STATE(29)] = 700,
  [SMALL_STATE(30)] = 716,
  [SMALL_STATE(31)] = 732,
  [SMALL_STATE(32)] = 744,
  [SMALL_STATE(33)] = 756,
  [SMALL_STATE(34)] = 772,
  [SMALL_STATE(35)] = 784,
  [SMALL_STATE(36)] = 796,
  [SMALL_STATE(37)] = 808,
  [SMALL_STATE(38)] = 824,
  [SMALL_STATE(39)] = 836,
  [SMALL_STATE(40)] = 852,
  [SMALL_STATE(41)] = 868,
  [SMALL_STATE(42)] = 884,
  [SMALL_STATE(43)] = 896,
  [SMALL_STATE(44)] = 910,
  [SMALL_STATE(45)] = 922,
  [SMALL_STATE(46)] = 934,
  [SMALL_STATE(47)] = 946,
  [SMALL_STATE(48)] = 958,
  [SMALL_STATE(49)] = 972,
  [SMALL_STATE(50)] = 986,
  [SMALL_STATE(51)] = 997,
  [SMALL_STATE(52)] = 1008,
  [SMALL_STATE(53)] = 1019,
  [SMALL_STATE(54)] = 1030,
  [SMALL_STATE(55)] = 1041,
  [SMALL_STATE(56)] = 1052,
  [SMALL_STATE(57)] = 1063,
  [SMALL_STATE(58)] = 1074,
  [SMALL_STATE(59)] = 1085,
  [SMALL_STATE(60)] = 1096,
  [SMALL_STATE(61)] = 1107,
  [SMALL_STATE(62)] = 1118,
  [SMALL_STATE(63)] = 1129,
  [SMALL_STATE(64)] = 1140,
  [SMALL_STATE(65)] = 1151,
  [SMALL_STATE(66)] = 1162,
  [SMALL_STATE(67)] = 1173,
  [SMALL_STATE(68)] = 1184,
  [SMALL_STATE(69)] = 1197,
  [SMALL_STATE(70)] = 1208,
  [SMALL_STATE(71)] = 1219,
  [SMALL_STATE(72)] = 1232,
  [SMALL_STATE(73)] = 1243,
  [SMALL_STATE(74)] = 1254,
  [SMALL_STATE(75)] = 1265,
  [SMALL_STATE(76)] = 1276,
  [SMALL_STATE(77)] = 1287,
  [SMALL_STATE(78)] = 1298,
  [SMALL_STATE(79)] = 1309,
  [SMALL_STATE(80)] = 1322,
  [SMALL_STATE(81)] = 1333,
  [SMALL_STATE(82)] = 1344,
  [SMALL_STATE(83)] = 1355,
  [SMALL_STATE(84)] = 1366,
  [SMALL_STATE(85)] = 1377,
  [SMALL_STATE(86)] = 1388,
  [SMALL_STATE(87)] = 1399,
  [SMALL_STATE(88)] = 1410,
  [SMALL_STATE(89)] = 1421,
  [SMALL_STATE(90)] = 1432,
  [SMALL_STATE(91)] = 1443,
  [SMALL_STATE(92)] = 1454,
  [SMALL_STATE(93)] = 1465,
  [SMALL_STATE(94)] = 1475,
  [SMALL_STATE(95)] = 1485,
  [SMALL_STATE(96)] = 1495,
  [SMALL_STATE(97)] = 1505,
  [SMALL_STATE(98)] = 1515,
  [SMALL_STATE(99)] = 1525,
  [SMALL_STATE(100)] = 1535,
  [SMALL_STATE(101)] = 1545,
  [SMALL_STATE(102)] = 1555,
  [SMALL_STATE(103)] = 1565,
  [SMALL_STATE(104)] = 1575,
  [SMALL_STATE(105)] = 1585,
  [SMALL_STATE(106)] = 1595,
  [SMALL_STATE(107)] = 1605,
  [SMALL_STATE(108)] = 1615,
  [SMALL_STATE(109)] = 1625,
  [SMALL_STATE(110)] = 1635,
  [SMALL_STATE(111)] = 1645,
  [SMALL_STATE(112)] = 1655,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, SHIFT(107),
  [5] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_lines, 0),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(4),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(38),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(45),
  [13] = {.entry = {.count = 1, .reusable = true}}, SHIFT(110),
  [15] = {.entry = {.count = 1, .reusable = false}}, SHIFT(109),
  [17] = {.entry = {.count = 1, .reusable = true}}, SHIFT(108),
  [19] = {.entry = {.count = 1, .reusable = true}}, SHIFT(109),
  [21] = {.entry = {.count = 1, .reusable = true}}, SHIFT(44),
  [23] = {.entry = {.count = 1, .reusable = true}}, SHIFT(106),
  [25] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [27] = {.entry = {.count = 1, .reusable = true}}, SHIFT(59),
  [29] = {.entry = {.count = 1, .reusable = true}}, SHIFT(20),
  [31] = {.entry = {.count = 1, .reusable = true}}, SHIFT(61),
  [33] = {.entry = {.count = 1, .reusable = true}}, SHIFT(68),
  [35] = {.entry = {.count = 1, .reusable = true}}, SHIFT(71),
  [37] = {.entry = {.count = 1, .reusable = true}}, SHIFT(78),
  [39] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [41] = {.entry = {.count = 1, .reusable = true}}, SHIFT(79),
  [43] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [45] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [47] = {.entry = {.count = 1, .reusable = true}}, SHIFT(85),
  [49] = {.entry = {.count = 1, .reusable = true}}, SHIFT(23),
  [51] = {.entry = {.count = 1, .reusable = true}}, SHIFT(96),
  [53] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
  [55] = {.entry = {.count = 1, .reusable = true}}, SHIFT(91),
  [57] = {.entry = {.count = 1, .reusable = true}}, SHIFT(32),
  [59] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [61] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [63] = {.entry = {.count = 1, .reusable = true}}, SHIFT(60),
  [65] = {.entry = {.count = 1, .reusable = true}}, SHIFT(102),
  [67] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [69] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_lines, 1),
  [71] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [73] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [75] = {.entry = {.count = 1, .reusable = true}}, SHIFT(101),
  [77] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_lines_repeat1, 2),
  [79] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_lines_repeat1, 2), SHIFT_REPEAT(4),
  [82] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_state_opt, 1),
  [84] = {.entry = {.count = 1, .reusable = true}}, SHIFT(34),
  [86] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_limit_spec, 2, .production_id = 7),
  [88] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_interface, 1, .production_id = 11),
  [90] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_state_opt_list_repeat1, 2),
  [92] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_state_opt_list_repeat1, 2), SHIFT_REPEAT(3),
  [95] = {.entry = {.count = 1, .reusable = true}}, SHIFT(51),
  [97] = {.entry = {.count = 1, .reusable = true}}, SHIFT(46),
  [99] = {.entry = {.count = 1, .reusable = true}}, SHIFT(47),
  [101] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_timeout_spec, 2, .production_id = 7),
  [103] = {.entry = {.count = 1, .reusable = true}}, SHIFT(53),
  [105] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_interface, 2, .production_id = 8),
  [107] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_state_opt_list, 2),
  [109] = {.entry = {.count = 1, .reusable = true}}, SHIFT(3),
  [111] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_state_opt, 4, .production_id = 13),
  [113] = {.entry = {.count = 1, .reusable = true}}, SHIFT(31),
  [115] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_state_opt_list, 1),
  [117] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_limit_list_repeat1, 2),
  [119] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_limit_list_repeat1, 2), SHIFT_REPEAT(14),
  [122] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_timeout_list, 1),
  [124] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
  [126] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_limit_list, 2),
  [128] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [130] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_state_opt, 5, .production_id = 13),
  [132] = {.entry = {.count = 1, .reusable = true}}, SHIFT(65),
  [134] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_interface_list, 1),
  [136] = {.entry = {.count = 1, .reusable = true}}, SHIFT(39),
  [138] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_state_opt, 2),
  [140] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_state_opt, 2, .production_id = 7),
  [142] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_timeout_list, 2),
  [144] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_if_bound_keyword, 1),
  [146] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_limit_list, 1),
  [148] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_interface_list, 2),
  [150] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_state_opt, 4, .production_id = 12),
  [152] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_timeout_list_repeat1, 2),
  [154] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_timeout_list_repeat1, 2), SHIFT_REPEAT(7),
  [157] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_floating_keyword, 1),
  [159] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_yes_keyword, 1),
  [161] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_no_keyword, 1),
  [163] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__reassemble_option, 2),
  [165] = {.entry = {.count = 1, .reusable = true}}, SHIFT(72),
  [167] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_interface_list_repeat1, 2),
  [169] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_interface_list_repeat1, 2), SHIFT_REPEAT(39),
  [172] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_option, 2, .production_id = 2),
  [174] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__debug_option, 2),
  [176] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__require_order_option, 2),
  [178] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_ruleset_optimizer, 1),
  [180] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__ruleset_optimization_option, 2, .production_id = 10),
  [182] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_lines_repeat1, 1),
  [184] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_line, 1),
  [186] = {.entry = {.count = 1, .reusable = true}}, SHIFT(83),
  [188] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_optimization_hint, 1),
  [190] = {.entry = {.count = 1, .reusable = true}}, SHIFT(81),
  [192] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__state_defaults_option, 2),
  [194] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__loginterface_option, 2, .production_id = 8),
  [196] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__state_policy_option, 2),
  [198] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__syncookies_option, 2),
  [200] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__loginterface_option, 2),
  [202] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__timeout_option, 2),
  [204] = {.entry = {.count = 1, .reusable = true}}, SHIFT(100),
  [206] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_ifspec, 3),
  [208] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__limit_option, 2),
  [210] = {.entry = {.count = 1, .reusable = false}}, SHIFT(73),
  [212] = {.entry = {.count = 1, .reusable = true}}, SHIFT(73),
  [214] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__reassemble_option, 3),
  [216] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__hostid_option, 2, .production_id = 7),
  [218] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__fingerprints_option, 2, .production_id = 6),
  [220] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__skip_option, 3),
  [222] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_ifspec, 1),
  [224] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__keep_counters_option, 1),
  [226] = {.entry = {.count = 1, .reusable = false}}, SHIFT(63),
  [228] = {.entry = {.count = 1, .reusable = false}}, SHIFT(66),
  [230] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__timeout_option, 4),
  [232] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__fail_policy_option, 2),
  [234] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__optimization_option, 2, .production_id = 9),
  [236] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__block_policy_option, 2),
  [238] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_option, 2, .production_id = 5),
  [240] = {.entry = {.count = 1, .reusable = true}}, SHIFT(52),
  [242] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_option, 2, .production_id = 4),
  [244] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string, 3),
  [246] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__limit_option, 4),
  [248] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_option, 2, .production_id = 3),
  [250] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_option, 2, .production_id = 1),
  [252] = {.entry = {.count = 1, .reusable = true}}, SHIFT(64),
  [254] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_option, 2),
  [256] = {.entry = {.count = 1, .reusable = true}}, SHIFT(69),
  [258] = {.entry = {.count = 1, .reusable = true}}, SHIFT(42),
  [260] = {.entry = {.count = 1, .reusable = true}}, SHIFT(26),
  [262] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [264] = {.entry = {.count = 1, .reusable = true}}, SHIFT(80),
  [266] = {.entry = {.count = 1, .reusable = true}}, SHIFT(95),
  [268] = {.entry = {.count = 1, .reusable = true}}, SHIFT(94),
  [270] = {.entry = {.count = 1, .reusable = false}}, SHIFT(107),
  [272] = {.entry = {.count = 1, .reusable = false}}, SHIFT(104),
  [274] = {.entry = {.count = 1, .reusable = true}}, SHIFT(24),
  [276] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [278] = {.entry = {.count = 1, .reusable = true}}, SHIFT(88),
  [280] = {.entry = {.count = 1, .reusable = true}}, SHIFT(87),
  [282] = {.entry = {.count = 1, .reusable = true}}, SHIFT(22),
  [284] = {.entry = {.count = 1, .reusable = true}}, SHIFT(98),
  [286] = {.entry = {.count = 1, .reusable = false}}, SHIFT(112),
  [288] = {.entry = {.count = 1, .reusable = true}}, SHIFT(99),
  [290] = {.entry = {.count = 1, .reusable = true}}, SHIFT(35),
  [292] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_timeout_type, 1),
  [294] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [296] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_comment, 2),
};

#ifdef __cplusplus
extern "C" {
#endif
#ifdef TREE_SITTER_HIDE_SYMBOLS
#define TS_PUBLIC
#elif defined(_WIN32)
#define TS_PUBLIC __declspec(dllexport)
#else
#define TS_PUBLIC __attribute__((visibility("default")))
#endif

TS_PUBLIC const TSLanguage *tree_sitter_pfconf() {
  static const TSLanguage language = {
    .version = LANGUAGE_VERSION,
    .symbol_count = SYMBOL_COUNT,
    .alias_count = ALIAS_COUNT,
    .token_count = TOKEN_COUNT,
    .external_token_count = EXTERNAL_TOKEN_COUNT,
    .state_count = STATE_COUNT,
    .large_state_count = LARGE_STATE_COUNT,
    .production_id_count = PRODUCTION_ID_COUNT,
    .field_count = FIELD_COUNT,
    .max_alias_sequence_length = MAX_ALIAS_SEQUENCE_LENGTH,
    .parse_table = &ts_parse_table[0][0],
    .small_parse_table = ts_small_parse_table,
    .small_parse_table_map = ts_small_parse_table_map,
    .parse_actions = ts_parse_actions,
    .symbol_names = ts_symbol_names,
    .field_names = ts_field_names,
    .field_map_slices = ts_field_map_slices,
    .field_map_entries = ts_field_map_entries,
    .symbol_metadata = ts_symbol_metadata,
    .public_symbol_map = ts_symbol_map,
    .alias_map = ts_non_terminal_alias_map,
    .alias_sequences = &ts_alias_sequences[0][0],
    .lex_modes = ts_lex_modes,
    .lex_fn = ts_lex,
    .keyword_lex_fn = ts_lex_keywords,
    .keyword_capture_token = sym_identifier,
    .primary_state_ids = ts_primary_state_ids,
  };
  return &language;
}
#ifdef __cplusplus
}
#endif
