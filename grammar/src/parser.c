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

static TSCharacterRange sym_identifier_character_set_1[] = {
  {'A', 'Z'}, {'_', '_'}, {'a', 'z'}, {0xaa, 0xaa}, {0xb5, 0xb5}, {0xba, 0xba}, {0xc0, 0xd6}, {0xd8, 0xf6},
  {0xf8, 0x2c1}, {0x2c6, 0x2d1}, {0x2e0, 0x2e4}, {0x2ec, 0x2ec}, {0x2ee, 0x2ee}, {0x370, 0x374}, {0x376, 0x377}, {0x37b, 0x37d},
  {0x37f, 0x37f}, {0x386, 0x386}, {0x388, 0x38a}, {0x38c, 0x38c}, {0x38e, 0x3a1}, {0x3a3, 0x3f5}, {0x3f7, 0x481}, {0x48a, 0x52f},
  {0x531, 0x556}, {0x559, 0x559}, {0x560, 0x588}, {0x5d0, 0x5ea}, {0x5ef, 0x5f2}, {0x620, 0x64a}, {0x66e, 0x66f}, {0x671, 0x6d3},
  {0x6d5, 0x6d5}, {0x6e5, 0x6e6}, {0x6ee, 0x6ef}, {0x6fa, 0x6fc}, {0x6ff, 0x6ff}, {0x710, 0x710}, {0x712, 0x72f}, {0x74d, 0x7a5},
  {0x7b1, 0x7b1}, {0x7ca, 0x7ea}, {0x7f4, 0x7f5}, {0x7fa, 0x7fa}, {0x800, 0x815}, {0x81a, 0x81a}, {0x824, 0x824}, {0x828, 0x828},
  {0x840, 0x858}, {0x860, 0x86a}, {0x870, 0x887}, {0x889, 0x88e}, {0x8a0, 0x8c9}, {0x904, 0x939}, {0x93d, 0x93d}, {0x950, 0x950},
  {0x958, 0x961}, {0x971, 0x980}, {0x985, 0x98c}, {0x98f, 0x990}, {0x993, 0x9a8}, {0x9aa, 0x9b0}, {0x9b2, 0x9b2}, {0x9b6, 0x9b9},
  {0x9bd, 0x9bd}, {0x9ce, 0x9ce}, {0x9dc, 0x9dd}, {0x9df, 0x9e1}, {0x9f0, 0x9f1}, {0x9fc, 0x9fc}, {0xa05, 0xa0a}, {0xa0f, 0xa10},
  {0xa13, 0xa28}, {0xa2a, 0xa30}, {0xa32, 0xa33}, {0xa35, 0xa36}, {0xa38, 0xa39}, {0xa59, 0xa5c}, {0xa5e, 0xa5e}, {0xa72, 0xa74},
  {0xa85, 0xa8d}, {0xa8f, 0xa91}, {0xa93, 0xaa8}, {0xaaa, 0xab0}, {0xab2, 0xab3}, {0xab5, 0xab9}, {0xabd, 0xabd}, {0xad0, 0xad0},
  {0xae0, 0xae1}, {0xaf9, 0xaf9}, {0xb05, 0xb0c}, {0xb0f, 0xb10}, {0xb13, 0xb28}, {0xb2a, 0xb30}, {0xb32, 0xb33}, {0xb35, 0xb39},
  {0xb3d, 0xb3d}, {0xb5c, 0xb5d}, {0xb5f, 0xb61}, {0xb71, 0xb71}, {0xb83, 0xb83}, {0xb85, 0xb8a}, {0xb8e, 0xb90}, {0xb92, 0xb95},
  {0xb99, 0xb9a}, {0xb9c, 0xb9c}, {0xb9e, 0xb9f}, {0xba3, 0xba4}, {0xba8, 0xbaa}, {0xbae, 0xbb9}, {0xbd0, 0xbd0}, {0xc05, 0xc0c},
  {0xc0e, 0xc10}, {0xc12, 0xc28}, {0xc2a, 0xc39}, {0xc3d, 0xc3d}, {0xc58, 0xc5a}, {0xc5d, 0xc5d}, {0xc60, 0xc61}, {0xc80, 0xc80},
  {0xc85, 0xc8c}, {0xc8e, 0xc90}, {0xc92, 0xca8}, {0xcaa, 0xcb3}, {0xcb5, 0xcb9}, {0xcbd, 0xcbd}, {0xcdd, 0xcde}, {0xce0, 0xce1},
  {0xcf1, 0xcf2}, {0xd04, 0xd0c}, {0xd0e, 0xd10}, {0xd12, 0xd3a}, {0xd3d, 0xd3d}, {0xd4e, 0xd4e}, {0xd54, 0xd56}, {0xd5f, 0xd61},
  {0xd7a, 0xd7f}, {0xd85, 0xd96}, {0xd9a, 0xdb1}, {0xdb3, 0xdbb}, {0xdbd, 0xdbd}, {0xdc0, 0xdc6}, {0xe01, 0xe30}, {0xe32, 0xe32},
  {0xe40, 0xe46}, {0xe81, 0xe82}, {0xe84, 0xe84}, {0xe86, 0xe8a}, {0xe8c, 0xea3}, {0xea5, 0xea5}, {0xea7, 0xeb0}, {0xeb2, 0xeb2},
  {0xebd, 0xebd}, {0xec0, 0xec4}, {0xec6, 0xec6}, {0xedc, 0xedf}, {0xf00, 0xf00}, {0xf40, 0xf47}, {0xf49, 0xf6c}, {0xf88, 0xf8c},
  {0x1000, 0x102a}, {0x103f, 0x103f}, {0x1050, 0x1055}, {0x105a, 0x105d}, {0x1061, 0x1061}, {0x1065, 0x1066}, {0x106e, 0x1070}, {0x1075, 0x1081},
  {0x108e, 0x108e}, {0x10a0, 0x10c5}, {0x10c7, 0x10c7}, {0x10cd, 0x10cd}, {0x10d0, 0x10fa}, {0x10fc, 0x1248}, {0x124a, 0x124d}, {0x1250, 0x1256},
  {0x1258, 0x1258}, {0x125a, 0x125d}, {0x1260, 0x1288}, {0x128a, 0x128d}, {0x1290, 0x12b0}, {0x12b2, 0x12b5}, {0x12b8, 0x12be}, {0x12c0, 0x12c0},
  {0x12c2, 0x12c5}, {0x12c8, 0x12d6}, {0x12d8, 0x1310}, {0x1312, 0x1315}, {0x1318, 0x135a}, {0x1380, 0x138f}, {0x13a0, 0x13f5}, {0x13f8, 0x13fd},
  {0x1401, 0x166c}, {0x166f, 0x167f}, {0x1681, 0x169a}, {0x16a0, 0x16ea}, {0x16ee, 0x16f8}, {0x1700, 0x1711}, {0x171f, 0x1731}, {0x1740, 0x1751},
  {0x1760, 0x176c}, {0x176e, 0x1770}, {0x1780, 0x17b3}, {0x17d7, 0x17d7}, {0x17dc, 0x17dc}, {0x1820, 0x1878}, {0x1880, 0x18a8}, {0x18aa, 0x18aa},
  {0x18b0, 0x18f5}, {0x1900, 0x191e}, {0x1950, 0x196d}, {0x1970, 0x1974}, {0x1980, 0x19ab}, {0x19b0, 0x19c9}, {0x1a00, 0x1a16}, {0x1a20, 0x1a54},
  {0x1aa7, 0x1aa7}, {0x1b05, 0x1b33}, {0x1b45, 0x1b4c}, {0x1b83, 0x1ba0}, {0x1bae, 0x1baf}, {0x1bba, 0x1be5}, {0x1c00, 0x1c23}, {0x1c4d, 0x1c4f},
  {0x1c5a, 0x1c7d}, {0x1c80, 0x1c88}, {0x1c90, 0x1cba}, {0x1cbd, 0x1cbf}, {0x1ce9, 0x1cec}, {0x1cee, 0x1cf3}, {0x1cf5, 0x1cf6}, {0x1cfa, 0x1cfa},
  {0x1d00, 0x1dbf}, {0x1e00, 0x1f15}, {0x1f18, 0x1f1d}, {0x1f20, 0x1f45}, {0x1f48, 0x1f4d}, {0x1f50, 0x1f57}, {0x1f59, 0x1f59}, {0x1f5b, 0x1f5b},
  {0x1f5d, 0x1f5d}, {0x1f5f, 0x1f7d}, {0x1f80, 0x1fb4}, {0x1fb6, 0x1fbc}, {0x1fbe, 0x1fbe}, {0x1fc2, 0x1fc4}, {0x1fc6, 0x1fcc}, {0x1fd0, 0x1fd3},
  {0x1fd6, 0x1fdb}, {0x1fe0, 0x1fec}, {0x1ff2, 0x1ff4}, {0x1ff6, 0x1ffc}, {0x2071, 0x2071}, {0x207f, 0x207f}, {0x2090, 0x209c}, {0x2102, 0x2102},
  {0x2107, 0x2107}, {0x210a, 0x2113}, {0x2115, 0x2115}, {0x2118, 0x211d}, {0x2124, 0x2124}, {0x2126, 0x2126}, {0x2128, 0x2128}, {0x212a, 0x2139},
  {0x213c, 0x213f}, {0x2145, 0x2149}, {0x214e, 0x214e}, {0x2160, 0x2188}, {0x2c00, 0x2ce4}, {0x2ceb, 0x2cee}, {0x2cf2, 0x2cf3}, {0x2d00, 0x2d25},
  {0x2d27, 0x2d27}, {0x2d2d, 0x2d2d}, {0x2d30, 0x2d67}, {0x2d6f, 0x2d6f}, {0x2d80, 0x2d96}, {0x2da0, 0x2da6}, {0x2da8, 0x2dae}, {0x2db0, 0x2db6},
  {0x2db8, 0x2dbe}, {0x2dc0, 0x2dc6}, {0x2dc8, 0x2dce}, {0x2dd0, 0x2dd6}, {0x2dd8, 0x2dde}, {0x3005, 0x3007}, {0x3021, 0x3029}, {0x3031, 0x3035},
  {0x3038, 0x303c}, {0x3041, 0x3096}, {0x309d, 0x309f}, {0x30a1, 0x30fa}, {0x30fc, 0x30ff}, {0x3105, 0x312f}, {0x3131, 0x318e}, {0x31a0, 0x31bf},
  {0x31f0, 0x31ff}, {0x3400, 0x4dbf}, {0x4e00, 0xa48c}, {0xa4d0, 0xa4fd}, {0xa500, 0xa60c}, {0xa610, 0xa61f}, {0xa62a, 0xa62b}, {0xa640, 0xa66e},
  {0xa67f, 0xa69d}, {0xa6a0, 0xa6ef}, {0xa717, 0xa71f}, {0xa722, 0xa788}, {0xa78b, 0xa7ca}, {0xa7d0, 0xa7d1}, {0xa7d3, 0xa7d3}, {0xa7d5, 0xa7d9},
  {0xa7f2, 0xa801}, {0xa803, 0xa805}, {0xa807, 0xa80a}, {0xa80c, 0xa822}, {0xa840, 0xa873}, {0xa882, 0xa8b3}, {0xa8f2, 0xa8f7}, {0xa8fb, 0xa8fb},
  {0xa8fd, 0xa8fe}, {0xa90a, 0xa925}, {0xa930, 0xa946}, {0xa960, 0xa97c}, {0xa984, 0xa9b2}, {0xa9cf, 0xa9cf}, {0xa9e0, 0xa9e4}, {0xa9e6, 0xa9ef},
  {0xa9fa, 0xa9fe}, {0xaa00, 0xaa28}, {0xaa40, 0xaa42}, {0xaa44, 0xaa4b}, {0xaa60, 0xaa76}, {0xaa7a, 0xaa7a}, {0xaa7e, 0xaaaf}, {0xaab1, 0xaab1},
  {0xaab5, 0xaab6}, {0xaab9, 0xaabd}, {0xaac0, 0xaac0}, {0xaac2, 0xaac2}, {0xaadb, 0xaadd}, {0xaae0, 0xaaea}, {0xaaf2, 0xaaf4}, {0xab01, 0xab06},
  {0xab09, 0xab0e}, {0xab11, 0xab16}, {0xab20, 0xab26}, {0xab28, 0xab2e}, {0xab30, 0xab5a}, {0xab5c, 0xab69}, {0xab70, 0xabe2}, {0xac00, 0xd7a3},
  {0xd7b0, 0xd7c6}, {0xd7cb, 0xd7fb}, {0xf900, 0xfa6d}, {0xfa70, 0xfad9}, {0xfb00, 0xfb06}, {0xfb13, 0xfb17}, {0xfb1d, 0xfb1d}, {0xfb1f, 0xfb28},
  {0xfb2a, 0xfb36}, {0xfb38, 0xfb3c}, {0xfb3e, 0xfb3e}, {0xfb40, 0xfb41}, {0xfb43, 0xfb44}, {0xfb46, 0xfbb1}, {0xfbd3, 0xfc5d}, {0xfc64, 0xfd3d},
  {0xfd50, 0xfd8f}, {0xfd92, 0xfdc7}, {0xfdf0, 0xfdf9}, {0xfe71, 0xfe71}, {0xfe73, 0xfe73}, {0xfe77, 0xfe77}, {0xfe79, 0xfe79}, {0xfe7b, 0xfe7b},
  {0xfe7d, 0xfe7d}, {0xfe7f, 0xfefc}, {0xff21, 0xff3a}, {0xff41, 0xff5a}, {0xff66, 0xff9d}, {0xffa0, 0xffbe}, {0xffc2, 0xffc7}, {0xffca, 0xffcf},
  {0xffd2, 0xffd7}, {0xffda, 0xffdc}, {0x10000, 0x1000b}, {0x1000d, 0x10026}, {0x10028, 0x1003a}, {0x1003c, 0x1003d}, {0x1003f, 0x1004d}, {0x10050, 0x1005d},
  {0x10080, 0x100fa}, {0x10140, 0x10174}, {0x10280, 0x1029c}, {0x102a0, 0x102d0}, {0x10300, 0x1031f}, {0x1032d, 0x1034a}, {0x10350, 0x10375}, {0x10380, 0x1039d},
  {0x103a0, 0x103c3}, {0x103c8, 0x103cf}, {0x103d1, 0x103d5}, {0x10400, 0x1049d}, {0x104b0, 0x104d3}, {0x104d8, 0x104fb}, {0x10500, 0x10527}, {0x10530, 0x10563},
  {0x10570, 0x1057a}, {0x1057c, 0x1058a}, {0x1058c, 0x10592}, {0x10594, 0x10595}, {0x10597, 0x105a1}, {0x105a3, 0x105b1}, {0x105b3, 0x105b9}, {0x105bb, 0x105bc},
  {0x10600, 0x10736}, {0x10740, 0x10755}, {0x10760, 0x10767}, {0x10780, 0x10785}, {0x10787, 0x107b0}, {0x107b2, 0x107ba}, {0x10800, 0x10805}, {0x10808, 0x10808},
  {0x1080a, 0x10835}, {0x10837, 0x10838}, {0x1083c, 0x1083c}, {0x1083f, 0x10855}, {0x10860, 0x10876}, {0x10880, 0x1089e}, {0x108e0, 0x108f2}, {0x108f4, 0x108f5},
  {0x10900, 0x10915}, {0x10920, 0x10939}, {0x10980, 0x109b7}, {0x109be, 0x109bf}, {0x10a00, 0x10a00}, {0x10a10, 0x10a13}, {0x10a15, 0x10a17}, {0x10a19, 0x10a35},
  {0x10a60, 0x10a7c}, {0x10a80, 0x10a9c}, {0x10ac0, 0x10ac7}, {0x10ac9, 0x10ae4}, {0x10b00, 0x10b35}, {0x10b40, 0x10b55}, {0x10b60, 0x10b72}, {0x10b80, 0x10b91},
  {0x10c00, 0x10c48}, {0x10c80, 0x10cb2}, {0x10cc0, 0x10cf2}, {0x10d00, 0x10d23}, {0x10e80, 0x10ea9}, {0x10eb0, 0x10eb1}, {0x10f00, 0x10f1c}, {0x10f27, 0x10f27},
  {0x10f30, 0x10f45}, {0x10f70, 0x10f81}, {0x10fb0, 0x10fc4}, {0x10fe0, 0x10ff6}, {0x11003, 0x11037}, {0x11071, 0x11072}, {0x11075, 0x11075}, {0x11083, 0x110af},
  {0x110d0, 0x110e8}, {0x11103, 0x11126}, {0x11144, 0x11144}, {0x11147, 0x11147}, {0x11150, 0x11172}, {0x11176, 0x11176}, {0x11183, 0x111b2}, {0x111c1, 0x111c4},
  {0x111da, 0x111da}, {0x111dc, 0x111dc}, {0x11200, 0x11211}, {0x11213, 0x1122b}, {0x1123f, 0x11240}, {0x11280, 0x11286}, {0x11288, 0x11288}, {0x1128a, 0x1128d},
  {0x1128f, 0x1129d}, {0x1129f, 0x112a8}, {0x112b0, 0x112de}, {0x11305, 0x1130c}, {0x1130f, 0x11310}, {0x11313, 0x11328}, {0x1132a, 0x11330}, {0x11332, 0x11333},
  {0x11335, 0x11339}, {0x1133d, 0x1133d}, {0x11350, 0x11350}, {0x1135d, 0x11361}, {0x11400, 0x11434}, {0x11447, 0x1144a}, {0x1145f, 0x11461}, {0x11480, 0x114af},
  {0x114c4, 0x114c5}, {0x114c7, 0x114c7}, {0x11580, 0x115ae}, {0x115d8, 0x115db}, {0x11600, 0x1162f}, {0x11644, 0x11644}, {0x11680, 0x116aa}, {0x116b8, 0x116b8},
  {0x11700, 0x1171a}, {0x11740, 0x11746}, {0x11800, 0x1182b}, {0x118a0, 0x118df}, {0x118ff, 0x11906}, {0x11909, 0x11909}, {0x1190c, 0x11913}, {0x11915, 0x11916},
  {0x11918, 0x1192f}, {0x1193f, 0x1193f}, {0x11941, 0x11941}, {0x119a0, 0x119a7}, {0x119aa, 0x119d0}, {0x119e1, 0x119e1}, {0x119e3, 0x119e3}, {0x11a00, 0x11a00},
  {0x11a0b, 0x11a32}, {0x11a3a, 0x11a3a}, {0x11a50, 0x11a50}, {0x11a5c, 0x11a89}, {0x11a9d, 0x11a9d}, {0x11ab0, 0x11af8}, {0x11c00, 0x11c08}, {0x11c0a, 0x11c2e},
  {0x11c40, 0x11c40}, {0x11c72, 0x11c8f}, {0x11d00, 0x11d06}, {0x11d08, 0x11d09}, {0x11d0b, 0x11d30}, {0x11d46, 0x11d46}, {0x11d60, 0x11d65}, {0x11d67, 0x11d68},
  {0x11d6a, 0x11d89}, {0x11d98, 0x11d98}, {0x11ee0, 0x11ef2}, {0x11f02, 0x11f02}, {0x11f04, 0x11f10}, {0x11f12, 0x11f33}, {0x11fb0, 0x11fb0}, {0x12000, 0x12399},
  {0x12400, 0x1246e}, {0x12480, 0x12543}, {0x12f90, 0x12ff0}, {0x13000, 0x1342f}, {0x13441, 0x13446}, {0x14400, 0x14646}, {0x16800, 0x16a38}, {0x16a40, 0x16a5e},
  {0x16a70, 0x16abe}, {0x16ad0, 0x16aed}, {0x16b00, 0x16b2f}, {0x16b40, 0x16b43}, {0x16b63, 0x16b77}, {0x16b7d, 0x16b8f}, {0x16e40, 0x16e7f}, {0x16f00, 0x16f4a},
  {0x16f50, 0x16f50}, {0x16f93, 0x16f9f}, {0x16fe0, 0x16fe1}, {0x16fe3, 0x16fe3}, {0x17000, 0x187f7}, {0x18800, 0x18cd5}, {0x18d00, 0x18d08}, {0x1aff0, 0x1aff3},
  {0x1aff5, 0x1affb}, {0x1affd, 0x1affe}, {0x1b000, 0x1b122}, {0x1b132, 0x1b132}, {0x1b150, 0x1b152}, {0x1b155, 0x1b155}, {0x1b164, 0x1b167}, {0x1b170, 0x1b2fb},
  {0x1bc00, 0x1bc6a}, {0x1bc70, 0x1bc7c}, {0x1bc80, 0x1bc88}, {0x1bc90, 0x1bc99}, {0x1d400, 0x1d454}, {0x1d456, 0x1d49c}, {0x1d49e, 0x1d49f}, {0x1d4a2, 0x1d4a2},
  {0x1d4a5, 0x1d4a6}, {0x1d4a9, 0x1d4ac}, {0x1d4ae, 0x1d4b9}, {0x1d4bb, 0x1d4bb}, {0x1d4bd, 0x1d4c3}, {0x1d4c5, 0x1d505}, {0x1d507, 0x1d50a}, {0x1d50d, 0x1d514},
  {0x1d516, 0x1d51c}, {0x1d51e, 0x1d539}, {0x1d53b, 0x1d53e}, {0x1d540, 0x1d544}, {0x1d546, 0x1d546}, {0x1d54a, 0x1d550}, {0x1d552, 0x1d6a5}, {0x1d6a8, 0x1d6c0},
  {0x1d6c2, 0x1d6da}, {0x1d6dc, 0x1d6fa}, {0x1d6fc, 0x1d714}, {0x1d716, 0x1d734}, {0x1d736, 0x1d74e}, {0x1d750, 0x1d76e}, {0x1d770, 0x1d788}, {0x1d78a, 0x1d7a8},
  {0x1d7aa, 0x1d7c2}, {0x1d7c4, 0x1d7cb}, {0x1df00, 0x1df1e}, {0x1df25, 0x1df2a}, {0x1e030, 0x1e06d}, {0x1e100, 0x1e12c}, {0x1e137, 0x1e13d}, {0x1e14e, 0x1e14e},
  {0x1e290, 0x1e2ad}, {0x1e2c0, 0x1e2eb}, {0x1e4d0, 0x1e4eb}, {0x1e7e0, 0x1e7e6}, {0x1e7e8, 0x1e7eb}, {0x1e7ed, 0x1e7ee}, {0x1e7f0, 0x1e7fe}, {0x1e800, 0x1e8c4},
  {0x1e900, 0x1e943}, {0x1e94b, 0x1e94b}, {0x1ee00, 0x1ee03}, {0x1ee05, 0x1ee1f}, {0x1ee21, 0x1ee22}, {0x1ee24, 0x1ee24}, {0x1ee27, 0x1ee27}, {0x1ee29, 0x1ee32},
  {0x1ee34, 0x1ee37}, {0x1ee39, 0x1ee39}, {0x1ee3b, 0x1ee3b}, {0x1ee42, 0x1ee42}, {0x1ee47, 0x1ee47}, {0x1ee49, 0x1ee49}, {0x1ee4b, 0x1ee4b}, {0x1ee4d, 0x1ee4f},
  {0x1ee51, 0x1ee52}, {0x1ee54, 0x1ee54}, {0x1ee57, 0x1ee57}, {0x1ee59, 0x1ee59}, {0x1ee5b, 0x1ee5b}, {0x1ee5d, 0x1ee5d}, {0x1ee5f, 0x1ee5f}, {0x1ee61, 0x1ee62},
  {0x1ee64, 0x1ee64}, {0x1ee67, 0x1ee6a}, {0x1ee6c, 0x1ee72}, {0x1ee74, 0x1ee77}, {0x1ee79, 0x1ee7c}, {0x1ee7e, 0x1ee7e}, {0x1ee80, 0x1ee89}, {0x1ee8b, 0x1ee9b},
  {0x1eea1, 0x1eea3}, {0x1eea5, 0x1eea9}, {0x1eeab, 0x1eebb}, {0x20000, 0x2a6df}, {0x2a700, 0x2b739}, {0x2b740, 0x2b81d}, {0x2b820, 0x2cea1}, {0x2ceb0, 0x2ebe0},
  {0x2ebf0, 0x2ee5d}, {0x2f800, 0x2fa1d}, {0x30000, 0x3134a}, {0x31350, 0x323af},
};

static TSCharacterRange sym_identifier_character_set_2[] = {
  {'0', '9'}, {'A', 'Z'}, {'_', '_'}, {'a', 'z'}, {0xaa, 0xaa}, {0xb5, 0xb5}, {0xb7, 0xb7}, {0xba, 0xba},
  {0xc0, 0xd6}, {0xd8, 0xf6}, {0xf8, 0x2c1}, {0x2c6, 0x2d1}, {0x2e0, 0x2e4}, {0x2ec, 0x2ec}, {0x2ee, 0x2ee}, {0x300, 0x374},
  {0x376, 0x377}, {0x37b, 0x37d}, {0x37f, 0x37f}, {0x386, 0x38a}, {0x38c, 0x38c}, {0x38e, 0x3a1}, {0x3a3, 0x3f5}, {0x3f7, 0x481},
  {0x483, 0x487}, {0x48a, 0x52f}, {0x531, 0x556}, {0x559, 0x559}, {0x560, 0x588}, {0x591, 0x5bd}, {0x5bf, 0x5bf}, {0x5c1, 0x5c2},
  {0x5c4, 0x5c5}, {0x5c7, 0x5c7}, {0x5d0, 0x5ea}, {0x5ef, 0x5f2}, {0x610, 0x61a}, {0x620, 0x669}, {0x66e, 0x6d3}, {0x6d5, 0x6dc},
  {0x6df, 0x6e8}, {0x6ea, 0x6fc}, {0x6ff, 0x6ff}, {0x710, 0x74a}, {0x74d, 0x7b1}, {0x7c0, 0x7f5}, {0x7fa, 0x7fa}, {0x7fd, 0x7fd},
  {0x800, 0x82d}, {0x840, 0x85b}, {0x860, 0x86a}, {0x870, 0x887}, {0x889, 0x88e}, {0x898, 0x8e1}, {0x8e3, 0x963}, {0x966, 0x96f},
  {0x971, 0x983}, {0x985, 0x98c}, {0x98f, 0x990}, {0x993, 0x9a8}, {0x9aa, 0x9b0}, {0x9b2, 0x9b2}, {0x9b6, 0x9b9}, {0x9bc, 0x9c4},
  {0x9c7, 0x9c8}, {0x9cb, 0x9ce}, {0x9d7, 0x9d7}, {0x9dc, 0x9dd}, {0x9df, 0x9e3}, {0x9e6, 0x9f1}, {0x9fc, 0x9fc}, {0x9fe, 0x9fe},
  {0xa01, 0xa03}, {0xa05, 0xa0a}, {0xa0f, 0xa10}, {0xa13, 0xa28}, {0xa2a, 0xa30}, {0xa32, 0xa33}, {0xa35, 0xa36}, {0xa38, 0xa39},
  {0xa3c, 0xa3c}, {0xa3e, 0xa42}, {0xa47, 0xa48}, {0xa4b, 0xa4d}, {0xa51, 0xa51}, {0xa59, 0xa5c}, {0xa5e, 0xa5e}, {0xa66, 0xa75},
  {0xa81, 0xa83}, {0xa85, 0xa8d}, {0xa8f, 0xa91}, {0xa93, 0xaa8}, {0xaaa, 0xab0}, {0xab2, 0xab3}, {0xab5, 0xab9}, {0xabc, 0xac5},
  {0xac7, 0xac9}, {0xacb, 0xacd}, {0xad0, 0xad0}, {0xae0, 0xae3}, {0xae6, 0xaef}, {0xaf9, 0xaff}, {0xb01, 0xb03}, {0xb05, 0xb0c},
  {0xb0f, 0xb10}, {0xb13, 0xb28}, {0xb2a, 0xb30}, {0xb32, 0xb33}, {0xb35, 0xb39}, {0xb3c, 0xb44}, {0xb47, 0xb48}, {0xb4b, 0xb4d},
  {0xb55, 0xb57}, {0xb5c, 0xb5d}, {0xb5f, 0xb63}, {0xb66, 0xb6f}, {0xb71, 0xb71}, {0xb82, 0xb83}, {0xb85, 0xb8a}, {0xb8e, 0xb90},
  {0xb92, 0xb95}, {0xb99, 0xb9a}, {0xb9c, 0xb9c}, {0xb9e, 0xb9f}, {0xba3, 0xba4}, {0xba8, 0xbaa}, {0xbae, 0xbb9}, {0xbbe, 0xbc2},
  {0xbc6, 0xbc8}, {0xbca, 0xbcd}, {0xbd0, 0xbd0}, {0xbd7, 0xbd7}, {0xbe6, 0xbef}, {0xc00, 0xc0c}, {0xc0e, 0xc10}, {0xc12, 0xc28},
  {0xc2a, 0xc39}, {0xc3c, 0xc44}, {0xc46, 0xc48}, {0xc4a, 0xc4d}, {0xc55, 0xc56}, {0xc58, 0xc5a}, {0xc5d, 0xc5d}, {0xc60, 0xc63},
  {0xc66, 0xc6f}, {0xc80, 0xc83}, {0xc85, 0xc8c}, {0xc8e, 0xc90}, {0xc92, 0xca8}, {0xcaa, 0xcb3}, {0xcb5, 0xcb9}, {0xcbc, 0xcc4},
  {0xcc6, 0xcc8}, {0xcca, 0xccd}, {0xcd5, 0xcd6}, {0xcdd, 0xcde}, {0xce0, 0xce3}, {0xce6, 0xcef}, {0xcf1, 0xcf3}, {0xd00, 0xd0c},
  {0xd0e, 0xd10}, {0xd12, 0xd44}, {0xd46, 0xd48}, {0xd4a, 0xd4e}, {0xd54, 0xd57}, {0xd5f, 0xd63}, {0xd66, 0xd6f}, {0xd7a, 0xd7f},
  {0xd81, 0xd83}, {0xd85, 0xd96}, {0xd9a, 0xdb1}, {0xdb3, 0xdbb}, {0xdbd, 0xdbd}, {0xdc0, 0xdc6}, {0xdca, 0xdca}, {0xdcf, 0xdd4},
  {0xdd6, 0xdd6}, {0xdd8, 0xddf}, {0xde6, 0xdef}, {0xdf2, 0xdf3}, {0xe01, 0xe3a}, {0xe40, 0xe4e}, {0xe50, 0xe59}, {0xe81, 0xe82},
  {0xe84, 0xe84}, {0xe86, 0xe8a}, {0xe8c, 0xea3}, {0xea5, 0xea5}, {0xea7, 0xebd}, {0xec0, 0xec4}, {0xec6, 0xec6}, {0xec8, 0xece},
  {0xed0, 0xed9}, {0xedc, 0xedf}, {0xf00, 0xf00}, {0xf18, 0xf19}, {0xf20, 0xf29}, {0xf35, 0xf35}, {0xf37, 0xf37}, {0xf39, 0xf39},
  {0xf3e, 0xf47}, {0xf49, 0xf6c}, {0xf71, 0xf84}, {0xf86, 0xf97}, {0xf99, 0xfbc}, {0xfc6, 0xfc6}, {0x1000, 0x1049}, {0x1050, 0x109d},
  {0x10a0, 0x10c5}, {0x10c7, 0x10c7}, {0x10cd, 0x10cd}, {0x10d0, 0x10fa}, {0x10fc, 0x1248}, {0x124a, 0x124d}, {0x1250, 0x1256}, {0x1258, 0x1258},
  {0x125a, 0x125d}, {0x1260, 0x1288}, {0x128a, 0x128d}, {0x1290, 0x12b0}, {0x12b2, 0x12b5}, {0x12b8, 0x12be}, {0x12c0, 0x12c0}, {0x12c2, 0x12c5},
  {0x12c8, 0x12d6}, {0x12d8, 0x1310}, {0x1312, 0x1315}, {0x1318, 0x135a}, {0x135d, 0x135f}, {0x1369, 0x1371}, {0x1380, 0x138f}, {0x13a0, 0x13f5},
  {0x13f8, 0x13fd}, {0x1401, 0x166c}, {0x166f, 0x167f}, {0x1681, 0x169a}, {0x16a0, 0x16ea}, {0x16ee, 0x16f8}, {0x1700, 0x1715}, {0x171f, 0x1734},
  {0x1740, 0x1753}, {0x1760, 0x176c}, {0x176e, 0x1770}, {0x1772, 0x1773}, {0x1780, 0x17d3}, {0x17d7, 0x17d7}, {0x17dc, 0x17dd}, {0x17e0, 0x17e9},
  {0x180b, 0x180d}, {0x180f, 0x1819}, {0x1820, 0x1878}, {0x1880, 0x18aa}, {0x18b0, 0x18f5}, {0x1900, 0x191e}, {0x1920, 0x192b}, {0x1930, 0x193b},
  {0x1946, 0x196d}, {0x1970, 0x1974}, {0x1980, 0x19ab}, {0x19b0, 0x19c9}, {0x19d0, 0x19da}, {0x1a00, 0x1a1b}, {0x1a20, 0x1a5e}, {0x1a60, 0x1a7c},
  {0x1a7f, 0x1a89}, {0x1a90, 0x1a99}, {0x1aa7, 0x1aa7}, {0x1ab0, 0x1abd}, {0x1abf, 0x1ace}, {0x1b00, 0x1b4c}, {0x1b50, 0x1b59}, {0x1b6b, 0x1b73},
  {0x1b80, 0x1bf3}, {0x1c00, 0x1c37}, {0x1c40, 0x1c49}, {0x1c4d, 0x1c7d}, {0x1c80, 0x1c88}, {0x1c90, 0x1cba}, {0x1cbd, 0x1cbf}, {0x1cd0, 0x1cd2},
  {0x1cd4, 0x1cfa}, {0x1d00, 0x1f15}, {0x1f18, 0x1f1d}, {0x1f20, 0x1f45}, {0x1f48, 0x1f4d}, {0x1f50, 0x1f57}, {0x1f59, 0x1f59}, {0x1f5b, 0x1f5b},
  {0x1f5d, 0x1f5d}, {0x1f5f, 0x1f7d}, {0x1f80, 0x1fb4}, {0x1fb6, 0x1fbc}, {0x1fbe, 0x1fbe}, {0x1fc2, 0x1fc4}, {0x1fc6, 0x1fcc}, {0x1fd0, 0x1fd3},
  {0x1fd6, 0x1fdb}, {0x1fe0, 0x1fec}, {0x1ff2, 0x1ff4}, {0x1ff6, 0x1ffc}, {0x200c, 0x200d}, {0x203f, 0x2040}, {0x2054, 0x2054}, {0x2071, 0x2071},
  {0x207f, 0x207f}, {0x2090, 0x209c}, {0x20d0, 0x20dc}, {0x20e1, 0x20e1}, {0x20e5, 0x20f0}, {0x2102, 0x2102}, {0x2107, 0x2107}, {0x210a, 0x2113},
  {0x2115, 0x2115}, {0x2118, 0x211d}, {0x2124, 0x2124}, {0x2126, 0x2126}, {0x2128, 0x2128}, {0x212a, 0x2139}, {0x213c, 0x213f}, {0x2145, 0x2149},
  {0x214e, 0x214e}, {0x2160, 0x2188}, {0x2c00, 0x2ce4}, {0x2ceb, 0x2cf3}, {0x2d00, 0x2d25}, {0x2d27, 0x2d27}, {0x2d2d, 0x2d2d}, {0x2d30, 0x2d67},
  {0x2d6f, 0x2d6f}, {0x2d7f, 0x2d96}, {0x2da0, 0x2da6}, {0x2da8, 0x2dae}, {0x2db0, 0x2db6}, {0x2db8, 0x2dbe}, {0x2dc0, 0x2dc6}, {0x2dc8, 0x2dce},
  {0x2dd0, 0x2dd6}, {0x2dd8, 0x2dde}, {0x2de0, 0x2dff}, {0x3005, 0x3007}, {0x3021, 0x302f}, {0x3031, 0x3035}, {0x3038, 0x303c}, {0x3041, 0x3096},
  {0x3099, 0x309a}, {0x309d, 0x309f}, {0x30a1, 0x30ff}, {0x3105, 0x312f}, {0x3131, 0x318e}, {0x31a0, 0x31bf}, {0x31f0, 0x31ff}, {0x3400, 0x4dbf},
  {0x4e00, 0xa48c}, {0xa4d0, 0xa4fd}, {0xa500, 0xa60c}, {0xa610, 0xa62b}, {0xa640, 0xa66f}, {0xa674, 0xa67d}, {0xa67f, 0xa6f1}, {0xa717, 0xa71f},
  {0xa722, 0xa788}, {0xa78b, 0xa7ca}, {0xa7d0, 0xa7d1}, {0xa7d3, 0xa7d3}, {0xa7d5, 0xa7d9}, {0xa7f2, 0xa827}, {0xa82c, 0xa82c}, {0xa840, 0xa873},
  {0xa880, 0xa8c5}, {0xa8d0, 0xa8d9}, {0xa8e0, 0xa8f7}, {0xa8fb, 0xa8fb}, {0xa8fd, 0xa92d}, {0xa930, 0xa953}, {0xa960, 0xa97c}, {0xa980, 0xa9c0},
  {0xa9cf, 0xa9d9}, {0xa9e0, 0xa9fe}, {0xaa00, 0xaa36}, {0xaa40, 0xaa4d}, {0xaa50, 0xaa59}, {0xaa60, 0xaa76}, {0xaa7a, 0xaac2}, {0xaadb, 0xaadd},
  {0xaae0, 0xaaef}, {0xaaf2, 0xaaf6}, {0xab01, 0xab06}, {0xab09, 0xab0e}, {0xab11, 0xab16}, {0xab20, 0xab26}, {0xab28, 0xab2e}, {0xab30, 0xab5a},
  {0xab5c, 0xab69}, {0xab70, 0xabea}, {0xabec, 0xabed}, {0xabf0, 0xabf9}, {0xac00, 0xd7a3}, {0xd7b0, 0xd7c6}, {0xd7cb, 0xd7fb}, {0xf900, 0xfa6d},
  {0xfa70, 0xfad9}, {0xfb00, 0xfb06}, {0xfb13, 0xfb17}, {0xfb1d, 0xfb28}, {0xfb2a, 0xfb36}, {0xfb38, 0xfb3c}, {0xfb3e, 0xfb3e}, {0xfb40, 0xfb41},
  {0xfb43, 0xfb44}, {0xfb46, 0xfbb1}, {0xfbd3, 0xfc5d}, {0xfc64, 0xfd3d}, {0xfd50, 0xfd8f}, {0xfd92, 0xfdc7}, {0xfdf0, 0xfdf9}, {0xfe00, 0xfe0f},
  {0xfe20, 0xfe2f}, {0xfe33, 0xfe34}, {0xfe4d, 0xfe4f}, {0xfe71, 0xfe71}, {0xfe73, 0xfe73}, {0xfe77, 0xfe77}, {0xfe79, 0xfe79}, {0xfe7b, 0xfe7b},
  {0xfe7d, 0xfe7d}, {0xfe7f, 0xfefc}, {0xff10, 0xff19}, {0xff21, 0xff3a}, {0xff3f, 0xff3f}, {0xff41, 0xff5a}, {0xff65, 0xffbe}, {0xffc2, 0xffc7},
  {0xffca, 0xffcf}, {0xffd2, 0xffd7}, {0xffda, 0xffdc}, {0x10000, 0x1000b}, {0x1000d, 0x10026}, {0x10028, 0x1003a}, {0x1003c, 0x1003d}, {0x1003f, 0x1004d},
  {0x10050, 0x1005d}, {0x10080, 0x100fa}, {0x10140, 0x10174}, {0x101fd, 0x101fd}, {0x10280, 0x1029c}, {0x102a0, 0x102d0}, {0x102e0, 0x102e0}, {0x10300, 0x1031f},
  {0x1032d, 0x1034a}, {0x10350, 0x1037a}, {0x10380, 0x1039d}, {0x103a0, 0x103c3}, {0x103c8, 0x103cf}, {0x103d1, 0x103d5}, {0x10400, 0x1049d}, {0x104a0, 0x104a9},
  {0x104b0, 0x104d3}, {0x104d8, 0x104fb}, {0x10500, 0x10527}, {0x10530, 0x10563}, {0x10570, 0x1057a}, {0x1057c, 0x1058a}, {0x1058c, 0x10592}, {0x10594, 0x10595},
  {0x10597, 0x105a1}, {0x105a3, 0x105b1}, {0x105b3, 0x105b9}, {0x105bb, 0x105bc}, {0x10600, 0x10736}, {0x10740, 0x10755}, {0x10760, 0x10767}, {0x10780, 0x10785},
  {0x10787, 0x107b0}, {0x107b2, 0x107ba}, {0x10800, 0x10805}, {0x10808, 0x10808}, {0x1080a, 0x10835}, {0x10837, 0x10838}, {0x1083c, 0x1083c}, {0x1083f, 0x10855},
  {0x10860, 0x10876}, {0x10880, 0x1089e}, {0x108e0, 0x108f2}, {0x108f4, 0x108f5}, {0x10900, 0x10915}, {0x10920, 0x10939}, {0x10980, 0x109b7}, {0x109be, 0x109bf},
  {0x10a00, 0x10a03}, {0x10a05, 0x10a06}, {0x10a0c, 0x10a13}, {0x10a15, 0x10a17}, {0x10a19, 0x10a35}, {0x10a38, 0x10a3a}, {0x10a3f, 0x10a3f}, {0x10a60, 0x10a7c},
  {0x10a80, 0x10a9c}, {0x10ac0, 0x10ac7}, {0x10ac9, 0x10ae6}, {0x10b00, 0x10b35}, {0x10b40, 0x10b55}, {0x10b60, 0x10b72}, {0x10b80, 0x10b91}, {0x10c00, 0x10c48},
  {0x10c80, 0x10cb2}, {0x10cc0, 0x10cf2}, {0x10d00, 0x10d27}, {0x10d30, 0x10d39}, {0x10e80, 0x10ea9}, {0x10eab, 0x10eac}, {0x10eb0, 0x10eb1}, {0x10efd, 0x10f1c},
  {0x10f27, 0x10f27}, {0x10f30, 0x10f50}, {0x10f70, 0x10f85}, {0x10fb0, 0x10fc4}, {0x10fe0, 0x10ff6}, {0x11000, 0x11046}, {0x11066, 0x11075}, {0x1107f, 0x110ba},
  {0x110c2, 0x110c2}, {0x110d0, 0x110e8}, {0x110f0, 0x110f9}, {0x11100, 0x11134}, {0x11136, 0x1113f}, {0x11144, 0x11147}, {0x11150, 0x11173}, {0x11176, 0x11176},
  {0x11180, 0x111c4}, {0x111c9, 0x111cc}, {0x111ce, 0x111da}, {0x111dc, 0x111dc}, {0x11200, 0x11211}, {0x11213, 0x11237}, {0x1123e, 0x11241}, {0x11280, 0x11286},
  {0x11288, 0x11288}, {0x1128a, 0x1128d}, {0x1128f, 0x1129d}, {0x1129f, 0x112a8}, {0x112b0, 0x112ea}, {0x112f0, 0x112f9}, {0x11300, 0x11303}, {0x11305, 0x1130c},
  {0x1130f, 0x11310}, {0x11313, 0x11328}, {0x1132a, 0x11330}, {0x11332, 0x11333}, {0x11335, 0x11339}, {0x1133b, 0x11344}, {0x11347, 0x11348}, {0x1134b, 0x1134d},
  {0x11350, 0x11350}, {0x11357, 0x11357}, {0x1135d, 0x11363}, {0x11366, 0x1136c}, {0x11370, 0x11374}, {0x11400, 0x1144a}, {0x11450, 0x11459}, {0x1145e, 0x11461},
  {0x11480, 0x114c5}, {0x114c7, 0x114c7}, {0x114d0, 0x114d9}, {0x11580, 0x115b5}, {0x115b8, 0x115c0}, {0x115d8, 0x115dd}, {0x11600, 0x11640}, {0x11644, 0x11644},
  {0x11650, 0x11659}, {0x11680, 0x116b8}, {0x116c0, 0x116c9}, {0x11700, 0x1171a}, {0x1171d, 0x1172b}, {0x11730, 0x11739}, {0x11740, 0x11746}, {0x11800, 0x1183a},
  {0x118a0, 0x118e9}, {0x118ff, 0x11906}, {0x11909, 0x11909}, {0x1190c, 0x11913}, {0x11915, 0x11916}, {0x11918, 0x11935}, {0x11937, 0x11938}, {0x1193b, 0x11943},
  {0x11950, 0x11959}, {0x119a0, 0x119a7}, {0x119aa, 0x119d7}, {0x119da, 0x119e1}, {0x119e3, 0x119e4}, {0x11a00, 0x11a3e}, {0x11a47, 0x11a47}, {0x11a50, 0x11a99},
  {0x11a9d, 0x11a9d}, {0x11ab0, 0x11af8}, {0x11c00, 0x11c08}, {0x11c0a, 0x11c36}, {0x11c38, 0x11c40}, {0x11c50, 0x11c59}, {0x11c72, 0x11c8f}, {0x11c92, 0x11ca7},
  {0x11ca9, 0x11cb6}, {0x11d00, 0x11d06}, {0x11d08, 0x11d09}, {0x11d0b, 0x11d36}, {0x11d3a, 0x11d3a}, {0x11d3c, 0x11d3d}, {0x11d3f, 0x11d47}, {0x11d50, 0x11d59},
  {0x11d60, 0x11d65}, {0x11d67, 0x11d68}, {0x11d6a, 0x11d8e}, {0x11d90, 0x11d91}, {0x11d93, 0x11d98}, {0x11da0, 0x11da9}, {0x11ee0, 0x11ef6}, {0x11f00, 0x11f10},
  {0x11f12, 0x11f3a}, {0x11f3e, 0x11f42}, {0x11f50, 0x11f59}, {0x11fb0, 0x11fb0}, {0x12000, 0x12399}, {0x12400, 0x1246e}, {0x12480, 0x12543}, {0x12f90, 0x12ff0},
  {0x13000, 0x1342f}, {0x13440, 0x13455}, {0x14400, 0x14646}, {0x16800, 0x16a38}, {0x16a40, 0x16a5e}, {0x16a60, 0x16a69}, {0x16a70, 0x16abe}, {0x16ac0, 0x16ac9},
  {0x16ad0, 0x16aed}, {0x16af0, 0x16af4}, {0x16b00, 0x16b36}, {0x16b40, 0x16b43}, {0x16b50, 0x16b59}, {0x16b63, 0x16b77}, {0x16b7d, 0x16b8f}, {0x16e40, 0x16e7f},
  {0x16f00, 0x16f4a}, {0x16f4f, 0x16f87}, {0x16f8f, 0x16f9f}, {0x16fe0, 0x16fe1}, {0x16fe3, 0x16fe4}, {0x16ff0, 0x16ff1}, {0x17000, 0x187f7}, {0x18800, 0x18cd5},
  {0x18d00, 0x18d08}, {0x1aff0, 0x1aff3}, {0x1aff5, 0x1affb}, {0x1affd, 0x1affe}, {0x1b000, 0x1b122}, {0x1b132, 0x1b132}, {0x1b150, 0x1b152}, {0x1b155, 0x1b155},
  {0x1b164, 0x1b167}, {0x1b170, 0x1b2fb}, {0x1bc00, 0x1bc6a}, {0x1bc70, 0x1bc7c}, {0x1bc80, 0x1bc88}, {0x1bc90, 0x1bc99}, {0x1bc9d, 0x1bc9e}, {0x1cf00, 0x1cf2d},
  {0x1cf30, 0x1cf46}, {0x1d165, 0x1d169}, {0x1d16d, 0x1d172}, {0x1d17b, 0x1d182}, {0x1d185, 0x1d18b}, {0x1d1aa, 0x1d1ad}, {0x1d242, 0x1d244}, {0x1d400, 0x1d454},
  {0x1d456, 0x1d49c}, {0x1d49e, 0x1d49f}, {0x1d4a2, 0x1d4a2}, {0x1d4a5, 0x1d4a6}, {0x1d4a9, 0x1d4ac}, {0x1d4ae, 0x1d4b9}, {0x1d4bb, 0x1d4bb}, {0x1d4bd, 0x1d4c3},
  {0x1d4c5, 0x1d505}, {0x1d507, 0x1d50a}, {0x1d50d, 0x1d514}, {0x1d516, 0x1d51c}, {0x1d51e, 0x1d539}, {0x1d53b, 0x1d53e}, {0x1d540, 0x1d544}, {0x1d546, 0x1d546},
  {0x1d54a, 0x1d550}, {0x1d552, 0x1d6a5}, {0x1d6a8, 0x1d6c0}, {0x1d6c2, 0x1d6da}, {0x1d6dc, 0x1d6fa}, {0x1d6fc, 0x1d714}, {0x1d716, 0x1d734}, {0x1d736, 0x1d74e},
  {0x1d750, 0x1d76e}, {0x1d770, 0x1d788}, {0x1d78a, 0x1d7a8}, {0x1d7aa, 0x1d7c2}, {0x1d7c4, 0x1d7cb}, {0x1d7ce, 0x1d7ff}, {0x1da00, 0x1da36}, {0x1da3b, 0x1da6c},
  {0x1da75, 0x1da75}, {0x1da84, 0x1da84}, {0x1da9b, 0x1da9f}, {0x1daa1, 0x1daaf}, {0x1df00, 0x1df1e}, {0x1df25, 0x1df2a}, {0x1e000, 0x1e006}, {0x1e008, 0x1e018},
  {0x1e01b, 0x1e021}, {0x1e023, 0x1e024}, {0x1e026, 0x1e02a}, {0x1e030, 0x1e06d}, {0x1e08f, 0x1e08f}, {0x1e100, 0x1e12c}, {0x1e130, 0x1e13d}, {0x1e140, 0x1e149},
  {0x1e14e, 0x1e14e}, {0x1e290, 0x1e2ae}, {0x1e2c0, 0x1e2f9}, {0x1e4d0, 0x1e4f9}, {0x1e7e0, 0x1e7e6}, {0x1e7e8, 0x1e7eb}, {0x1e7ed, 0x1e7ee}, {0x1e7f0, 0x1e7fe},
  {0x1e800, 0x1e8c4}, {0x1e8d0, 0x1e8d6}, {0x1e900, 0x1e94b}, {0x1e950, 0x1e959}, {0x1ee00, 0x1ee03}, {0x1ee05, 0x1ee1f}, {0x1ee21, 0x1ee22}, {0x1ee24, 0x1ee24},
  {0x1ee27, 0x1ee27}, {0x1ee29, 0x1ee32}, {0x1ee34, 0x1ee37}, {0x1ee39, 0x1ee39}, {0x1ee3b, 0x1ee3b}, {0x1ee42, 0x1ee42}, {0x1ee47, 0x1ee47}, {0x1ee49, 0x1ee49},
  {0x1ee4b, 0x1ee4b}, {0x1ee4d, 0x1ee4f}, {0x1ee51, 0x1ee52}, {0x1ee54, 0x1ee54}, {0x1ee57, 0x1ee57}, {0x1ee59, 0x1ee59}, {0x1ee5b, 0x1ee5b}, {0x1ee5d, 0x1ee5d},
  {0x1ee5f, 0x1ee5f}, {0x1ee61, 0x1ee62}, {0x1ee64, 0x1ee64}, {0x1ee67, 0x1ee6a}, {0x1ee6c, 0x1ee72}, {0x1ee74, 0x1ee77}, {0x1ee79, 0x1ee7c}, {0x1ee7e, 0x1ee7e},
  {0x1ee80, 0x1ee89}, {0x1ee8b, 0x1ee9b}, {0x1eea1, 0x1eea3}, {0x1eea5, 0x1eea9}, {0x1eeab, 0x1eebb}, {0x1fbf0, 0x1fbf9}, {0x20000, 0x2a6df}, {0x2a700, 0x2b739},
  {0x2b740, 0x2b81d}, {0x2b820, 0x2cea1}, {0x2ceb0, 0x2ebe0}, {0x2ebf0, 0x2ee5d}, {0x2f800, 0x2fa1d}, {0x30000, 0x3134a}, {0x31350, 0x323af}, {0xe0100, 0xe01ef},
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(343);
      ADVANCE_MAP(
        '!', 556,
        '"', 549,
        '#', 344,
        ',', 354,
        '/', 379,
        '0', 553,
        '<', 380,
        '>', 381,
      );
      if (lookahead == '\\') SKIP(336);
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
          lookahead == ' ') SKIP(0);
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(554);
      if (set_contains(sym_identifier_character_set_1, 668, lookahead)) ADVANCE(548);
      END_STATE();
    case 1:
      if (lookahead == '\n') SKIP(13);
      END_STATE();
    case 2:
      if (lookahead == '\n') SKIP(13);
      if (lookahead == '\r') SKIP(1);
      END_STATE();
    case 3:
      if (lookahead == '\n') SKIP(14);
      END_STATE();
    case 4:
      if (lookahead == '\n') SKIP(14);
      if (lookahead == '\r') SKIP(3);
      END_STATE();
    case 5:
      if (lookahead == '\n') SKIP(15);
      END_STATE();
    case 6:
      if (lookahead == '\n') SKIP(15);
      if (lookahead == '\r') SKIP(5);
      END_STATE();
    case 7:
      if (lookahead == '\n') SKIP(16);
      END_STATE();
    case 8:
      if (lookahead == '\n') SKIP(16);
      if (lookahead == '\r') SKIP(7);
      END_STATE();
    case 9:
      if (lookahead == '\n') SKIP(17);
      END_STATE();
    case 10:
      if (lookahead == '\n') SKIP(17);
      if (lookahead == '\r') SKIP(9);
      END_STATE();
    case 11:
      if (lookahead == '\n') SKIP(18);
      END_STATE();
    case 12:
      if (lookahead == '\n') SKIP(18);
      if (lookahead == '\r') SKIP(11);
      END_STATE();
    case 13:
      if (lookahead == '#') ADVANCE(344);
      if (lookahead == '\\') SKIP(2);
      if (lookahead == 'a') ADVANCE(452);
      if (lookahead == 'i') ADVANCE(446);
      if (lookahead == 'm') ADVANCE(427);
      if (lookahead == 'n') ADVANCE(504);
      if (lookahead == 'o') ADVANCE(526);
      if (lookahead == 's') ADVANCE(442);
      if (lookahead == 't') ADVANCE(439);
      if (lookahead == 'u') ADVANCE(456);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(13);
      if (set_contains(sym_identifier_character_set_1, 668, lookahead)) ADVANCE(548);
      END_STATE();
    case 14:
      if (lookahead == '#') ADVANCE(344);
      if (lookahead == '\\') SKIP(4);
      if (lookahead == 'b') ADVANCE(487);
      if (lookahead == 'f') ADVANCE(429);
      if (lookahead == 'r') ADVANCE(458);
      if (lookahead == 's') ADVANCE(528);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(14);
      if (set_contains(sym_identifier_character_set_1, 668, lookahead)) ADVANCE(548);
      END_STATE();
    case 15:
      if (lookahead == '#') ADVANCE(344);
      if (lookahead == '\\') SKIP(6);
      if (lookahead == 'a') ADVANCE(452);
      if (lookahead == 'i') ADVANCE(447);
      if (lookahead == 'o') ADVANCE(526);
      if (lookahead == 's') ADVANCE(443);
      if (lookahead == 't') ADVANCE(439);
      if (lookahead == 'u') ADVANCE(456);
      if (lookahead == '{') ADVANCE(350);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(15);
      if (set_contains(sym_identifier_character_set_1, 668, lookahead)) ADVANCE(548);
      END_STATE();
    case 16:
      if (lookahead == '#') ADVANCE(344);
      if (lookahead == '\\') SKIP(8);
      if (lookahead == 'h') ADVANCE(480);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(16);
      if (set_contains(sym_identifier_character_set_1, 668, lookahead)) ADVANCE(548);
      END_STATE();
    case 17:
      if (lookahead == '#') ADVANCE(344);
      if (lookahead == '\\') SKIP(10);
      if (lookahead == 's') ADVANCE(519);
      if (lookahead == 't') ADVANCE(426);
      if (lookahead == '{') ADVANCE(350);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(17);
      if (set_contains(sym_identifier_character_set_1, 668, lookahead)) ADVANCE(548);
      END_STATE();
    case 18:
      if (lookahead == '#') ADVANCE(344);
      if (lookahead == '\\') SKIP(12);
      if (lookahead == 'i') ADVANCE(472);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(18);
      if (set_contains(sym_identifier_character_set_1, 668, lookahead)) ADVANCE(548);
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
      if (lookahead == '\n') SKIP(0);
      END_STATE();
    case 336:
      if (eof) ADVANCE(343);
      if (lookahead == '\n') SKIP(0);
      if (lookahead == '\r') SKIP(335);
      END_STATE();
    case 337:
      if (eof) ADVANCE(343);
      if (lookahead == '\n') SKIP(341);
      END_STATE();
    case 338:
      if (eof) ADVANCE(343);
      if (lookahead == '\n') SKIP(341);
      if (lookahead == '\r') SKIP(337);
      END_STATE();
    case 339:
      if (eof) ADVANCE(343);
      if (lookahead == '\n') SKIP(342);
      END_STATE();
    case 340:
      if (eof) ADVANCE(343);
      if (lookahead == '\n') SKIP(342);
      if (lookahead == '\r') SKIP(339);
      END_STATE();
    case 341:
      if (eof) ADVANCE(343);
      if (lookahead == '!') ADVANCE(556);
      if (lookahead == '#') ADVANCE(344);
      if (lookahead == ',') ADVANCE(354);
      if (lookahead == '\\') SKIP(338);
      if (lookahead == '{') ADVANCE(350);
      if (lookahead == '}') ADVANCE(351);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(341);
      if (set_contains(sym_identifier_character_set_1, 668, lookahead)) ADVANCE(548);
      END_STATE();
    case 342:
      if (eof) ADVANCE(343);
      if (lookahead == '#') ADVANCE(344);
      if (lookahead == '\\') SKIP(340);
      if (lookahead == 'n') ADVANCE(505);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(342);
      if (set_contains(sym_identifier_character_set_1, 668, lookahead)) ADVANCE(548);
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
          (0x0b <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(348);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead)) ADVANCE(349);
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
      if (set_contains(sym_identifier_character_set_2, 776, lookahead)) ADVANCE(548);
      END_STATE();
    case 383:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '-') ADVANCE(58);
      if (set_contains(sym_identifier_character_set_2, 776, lookahead)) ADVANCE(548);
      END_STATE();
    case 384:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '-') ADVANCE(292);
      if (set_contains(sym_identifier_character_set_2, 776, lookahead)) ADVANCE(548);
      END_STATE();
    case 385:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '-') ADVANCE(74);
      if (set_contains(sym_identifier_character_set_2, 776, lookahead)) ADVANCE(548);
      END_STATE();
    case 386:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '-') ADVANCE(21);
      if (set_contains(sym_identifier_character_set_2, 776, lookahead)) ADVANCE(548);
      END_STATE();
    case 387:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '-') ADVANCE(181);
      if (lookahead == '.') ADVANCE(294);
      if (set_contains(sym_identifier_character_set_2, 776, lookahead)) ADVANCE(548);
      END_STATE();
    case 388:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '-') ADVANCE(181);
      if (set_contains(sym_identifier_character_set_2, 776, lookahead)) ADVANCE(548);
      END_STATE();
    case 389:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '-') ADVANCE(221);
      if (set_contains(sym_identifier_character_set_2, 776, lookahead)) ADVANCE(548);
      END_STATE();
    case 390:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '-') ADVANCE(151);
      if (set_contains(sym_identifier_character_set_2, 776, lookahead)) ADVANCE(548);
      END_STATE();
    case 391:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '-') ADVANCE(68);
      if (set_contains(sym_identifier_character_set_2, 776, lookahead)) ADVANCE(548);
      END_STATE();
    case 392:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '-') ADVANCE(241);
      if (set_contains(sym_identifier_character_set_2, 776, lookahead)) ADVANCE(548);
      END_STATE();
    case 393:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '-') ADVANCE(130);
      if (set_contains(sym_identifier_character_set_2, 776, lookahead)) ADVANCE(548);
      END_STATE();
    case 394:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '-') ADVANCE(117);
      if (set_contains(sym_identifier_character_set_2, 776, lookahead)) ADVANCE(548);
      END_STATE();
    case 395:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '-') ADVANCE(298);
      if (set_contains(sym_identifier_character_set_2, 776, lookahead)) ADVANCE(548);
      END_STATE();
    case 396:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '-') ADVANCE(84);
      if (set_contains(sym_identifier_character_set_2, 776, lookahead)) ADVANCE(548);
      END_STATE();
    case 397:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '-') ADVANCE(106);
      if (set_contains(sym_identifier_character_set_2, 776, lookahead)) ADVANCE(548);
      END_STATE();
    case 398:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '-') ADVANCE(293);
      if (lookahead == '.') ADVANCE(83);
      if (lookahead == '6') ADVANCE(414);
      if (set_contains(sym_identifier_character_set_2, 776, lookahead)) ADVANCE(548);
      END_STATE();
    case 399:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '-') ADVANCE(242);
      if (set_contains(sym_identifier_character_set_2, 776, lookahead)) ADVANCE(548);
      END_STATE();
    case 400:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '-') ADVANCE(128);
      if (set_contains(sym_identifier_character_set_2, 776, lookahead)) ADVANCE(548);
      END_STATE();
    case 401:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '-') ADVANCE(202);
      if (set_contains(sym_identifier_character_set_2, 776, lookahead)) ADVANCE(548);
      END_STATE();
    case 402:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '-') ADVANCE(24);
      if (set_contains(sym_identifier_character_set_2, 776, lookahead)) ADVANCE(548);
      END_STATE();
    case 403:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '-') ADVANCE(57);
      if (set_contains(sym_identifier_character_set_2, 776, lookahead)) ADVANCE(548);
      END_STATE();
    case 404:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '-') ADVANCE(211);
      if (set_contains(sym_identifier_character_set_2, 776, lookahead)) ADVANCE(548);
      END_STATE();
    case 405:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '-') ADVANCE(256);
      if (set_contains(sym_identifier_character_set_2, 776, lookahead)) ADVANCE(548);
      END_STATE();
    case 406:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '-') ADVANCE(295);
      if (set_contains(sym_identifier_character_set_2, 776, lookahead)) ADVANCE(548);
      END_STATE();
    case 407:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '-') ADVANCE(214);
      if (set_contains(sym_identifier_character_set_2, 776, lookahead)) ADVANCE(548);
      END_STATE();
    case 408:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '-') ADVANCE(300);
      if (set_contains(sym_identifier_character_set_2, 776, lookahead)) ADVANCE(548);
      END_STATE();
    case 409:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '-') ADVANCE(230);
      if (set_contains(sym_identifier_character_set_2, 776, lookahead)) ADVANCE(548);
      END_STATE();
    case 410:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '-') ADVANCE(304);
      if (set_contains(sym_identifier_character_set_2, 776, lookahead)) ADVANCE(548);
      END_STATE();
    case 411:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '-') ADVANCE(306);
      if (set_contains(sym_identifier_character_set_2, 776, lookahead)) ADVANCE(548);
      END_STATE();
    case 412:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '-') ADVANCE(229);
      if (set_contains(sym_identifier_character_set_2, 776, lookahead)) ADVANCE(548);
      END_STATE();
    case 413:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '-') ADVANCE(316);
      if (set_contains(sym_identifier_character_set_2, 776, lookahead)) ADVANCE(548);
      END_STATE();
    case 414:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '-') ADVANCE(315);
      if (set_contains(sym_identifier_character_set_2, 776, lookahead)) ADVANCE(548);
      END_STATE();
    case 415:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '-') ADVANCE(34);
      if (set_contains(sym_identifier_character_set_2, 776, lookahead)) ADVANCE(548);
      END_STATE();
    case 416:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '-') ADVANCE(37);
      if (set_contains(sym_identifier_character_set_2, 776, lookahead)) ADVANCE(548);
      END_STATE();
    case 417:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '.') ADVANCE(46);
      if (set_contains(sym_identifier_character_set_2, 776, lookahead)) ADVANCE(548);
      END_STATE();
    case 418:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '.') ADVANCE(105);
      if (set_contains(sym_identifier_character_set_2, 776, lookahead)) ADVANCE(548);
      END_STATE();
    case 419:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '.') ADVANCE(83);
      if (set_contains(sym_identifier_character_set_2, 776, lookahead)) ADVANCE(548);
      END_STATE();
    case 420:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '.') ADVANCE(56);
      if (set_contains(sym_identifier_character_set_2, 776, lookahead)) ADVANCE(548);
      END_STATE();
    case 421:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '.') ADVANCE(100);
      if (set_contains(sym_identifier_character_set_2, 776, lookahead)) ADVANCE(548);
      END_STATE();
    case 422:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '.') ADVANCE(294);
      if (set_contains(sym_identifier_character_set_2, 776, lookahead)) ADVANCE(548);
      END_STATE();
    case 423:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '.') ADVANCE(109);
      if (set_contains(sym_identifier_character_set_2, 776, lookahead)) ADVANCE(548);
      END_STATE();
    case 424:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'a') ADVANCE(513);
      if (lookahead == 'i') ADVANCE(499);
      if (set_contains(sym_identifier_character_set_2, 776, lookahead)) ADVANCE(548);
      END_STATE();
    case 425:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'a') ADVANCE(435);
      if (lookahead == 'c') ADVANCE(506);
      if (set_contains(sym_identifier_character_set_2, 776, lookahead)) ADVANCE(548);
      END_STATE();
    case 426:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'a') ADVANCE(435);
      if (set_contains(sym_identifier_character_set_2, 776, lookahead)) ADVANCE(548);
      END_STATE();
    case 427:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'a') ADVANCE(545);
      if (set_contains(sym_identifier_character_set_2, 776, lookahead)) ADVANCE(548);
      END_STATE();
    case 428:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'a') ADVANCE(530);
      if (lookahead == 'o') ADVANCE(383);
      if (set_contains(sym_identifier_character_set_2, 776, lookahead)) ADVANCE(548);
      END_STATE();
    case 429:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'a') ADVANCE(482);
      if (set_contains(sym_identifier_character_set_2, 776, lookahead)) ADVANCE(548);
      END_STATE();
    case 430:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'a') ADVANCE(496);
      if (lookahead == 'd') ADVANCE(523);
      if (lookahead == 'e') ADVANCE(510);
      if (lookahead == 'o') ADVANCE(537);
      if (set_contains(sym_identifier_character_set_2, 776, lookahead)) ADVANCE(548);
      END_STATE();
    case 431:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'a') ADVANCE(527);
      if (lookahead == 'i') ADVANCE(440);
      if (set_contains(sym_identifier_character_set_2, 776, lookahead)) ADVANCE(548);
      END_STATE();
    case 432:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'a') ADVANCE(514);
      if (set_contains(sym_identifier_character_set_2, 776, lookahead)) ADVANCE(548);
      END_STATE();
    case 433:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'a') ADVANCE(535);
      if (set_contains(sym_identifier_character_set_2, 776, lookahead)) ADVANCE(548);
      END_STATE();
    case 434:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'a') ADVANCE(536);
      if (set_contains(sym_identifier_character_set_2, 776, lookahead)) ADVANCE(548);
      END_STATE();
    case 435:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'b') ADVANCE(492);
      if (set_contains(sym_identifier_character_set_2, 776, lookahead)) ADVANCE(548);
      END_STATE();
    case 436:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'c') ADVANCE(493);
      if (lookahead == 'f') ADVANCE(382);
      if (set_contains(sym_identifier_character_set_2, 776, lookahead)) ADVANCE(548);
      END_STATE();
    case 437:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'c') ADVANCE(387);
      if (set_contains(sym_identifier_character_set_2, 776, lookahead)) ADVANCE(548);
      END_STATE();
    case 438:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'c') ADVANCE(486);
      if (set_contains(sym_identifier_character_set_2, 776, lookahead)) ADVANCE(548);
      END_STATE();
    case 439:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'c') ADVANCE(506);
      if (set_contains(sym_identifier_character_set_2, 776, lookahead)) ADVANCE(548);
      END_STATE();
    case 440:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'c') ADVANCE(485);
      if (set_contains(sym_identifier_character_set_2, 776, lookahead)) ADVANCE(548);
      END_STATE();
    case 441:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'c') ADVANCE(531);
      if (lookahead == 'e') ADVANCE(533);
      if (lookahead == 'o') ADVANCE(538);
      if (lookahead == 'r') ADVANCE(437);
      if (lookahead == 't') ADVANCE(431);
      if (set_contains(sym_identifier_character_set_2, 776, lookahead)) ADVANCE(548);
      END_STATE();
    case 442:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'c') ADVANCE(531);
      if (lookahead == 'o') ADVANCE(541);
      if (lookahead == 'r') ADVANCE(444);
      if (set_contains(sym_identifier_character_set_2, 776, lookahead)) ADVANCE(548);
      END_STATE();
    case 443:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'c') ADVANCE(531);
      if (lookahead == 'r') ADVANCE(444);
      if (set_contains(sym_identifier_character_set_2, 776, lookahead)) ADVANCE(548);
      END_STATE();
    case 444:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'c') ADVANCE(422);
      if (set_contains(sym_identifier_character_set_2, 776, lookahead)) ADVANCE(548);
      END_STATE();
    case 445:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'c') ADVANCE(388);
      if (set_contains(sym_identifier_character_set_2, 776, lookahead)) ADVANCE(548);
      END_STATE();
    case 446:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'c') ADVANCE(494);
      if (lookahead == 'f') ADVANCE(382);
      if (set_contains(sym_identifier_character_set_2, 776, lookahead)) ADVANCE(548);
      END_STATE();
    case 447:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'c') ADVANCE(494);
      if (set_contains(sym_identifier_character_set_2, 776, lookahead)) ADVANCE(548);
      END_STATE();
    case 448:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'c') ADVANCE(409);
      if (set_contains(sym_identifier_character_set_2, 776, lookahead)) ADVANCE(548);
      END_STATE();
    case 449:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'c') ADVANCE(466);
      if (set_contains(sym_identifier_character_set_2, 776, lookahead)) ADVANCE(548);
      END_STATE();
    case 450:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'c') ADVANCE(468);
      if (set_contains(sym_identifier_character_set_2, 776, lookahead)) ADVANCE(548);
      END_STATE();
    case 451:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'd') ADVANCE(432);
      if (lookahead == 'l') ADVANCE(489);
      if (set_contains(sym_identifier_character_set_2, 776, lookahead)) ADVANCE(548);
      END_STATE();
    case 452:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'd') ADVANCE(432);
      if (set_contains(sym_identifier_character_set_2, 776, lookahead)) ADVANCE(548);
      END_STATE();
    case 453:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'd') ADVANCE(475);
      if (set_contains(sym_identifier_character_set_2, 776, lookahead)) ADVANCE(548);
      END_STATE();
    case 454:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'd') ADVANCE(502);
      if (set_contains(sym_identifier_character_set_2, 776, lookahead)) ADVANCE(548);
      END_STATE();
    case 455:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'd') ADVANCE(509);
      if (lookahead == 'r') ADVANCE(507);
      if (set_contains(sym_identifier_character_set_2, 776, lookahead)) ADVANCE(548);
      END_STATE();
    case 456:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'd') ADVANCE(509);
      if (set_contains(sym_identifier_character_set_2, 776, lookahead)) ADVANCE(548);
      END_STATE();
    case 457:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'd') ADVANCE(399);
      if (set_contains(sym_identifier_character_set_2, 776, lookahead)) ADVANCE(548);
      END_STATE();
    case 458:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(516);
      if (lookahead == 'u') ADVANCE(490);
      if (set_contains(sym_identifier_character_set_2, 776, lookahead)) ADVANCE(548);
      END_STATE();
    case 459:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(525);
      if (set_contains(sym_identifier_character_set_2, 776, lookahead)) ADVANCE(548);
      END_STATE();
    case 460:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(520);
      if (set_contains(sym_identifier_character_set_2, 776, lookahead)) ADVANCE(548);
      END_STATE();
    case 461:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(524);
      if (set_contains(sym_identifier_character_set_2, 776, lookahead)) ADVANCE(548);
      END_STATE();
    case 462:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(421);
      if (set_contains(sym_identifier_character_set_2, 776, lookahead)) ADVANCE(548);
      END_STATE();
    case 463:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(391);
      if (lookahead == 'i') ADVANCE(448);
      if (set_contains(sym_identifier_character_set_2, 776, lookahead)) ADVANCE(548);
      END_STATE();
    case 464:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(391);
      if (set_contains(sym_identifier_character_set_2, 776, lookahead)) ADVANCE(548);
      END_STATE();
    case 465:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(396);
      if (set_contains(sym_identifier_character_set_2, 776, lookahead)) ADVANCE(548);
      END_STATE();
    case 466:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(394);
      if (set_contains(sym_identifier_character_set_2, 776, lookahead)) ADVANCE(548);
      END_STATE();
    case 467:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(404);
      if (set_contains(sym_identifier_character_set_2, 776, lookahead)) ADVANCE(548);
      END_STATE();
    case 468:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(413);
      if (set_contains(sym_identifier_character_set_2, 776, lookahead)) ADVANCE(548);
      END_STATE();
    case 469:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(534);
      if (set_contains(sym_identifier_character_set_2, 776, lookahead)) ADVANCE(548);
      END_STATE();
    case 470:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(410);
      if (set_contains(sym_identifier_character_set_2, 776, lookahead)) ADVANCE(548);
      END_STATE();
    case 471:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(411);
      if (set_contains(sym_identifier_character_set_2, 776, lookahead)) ADVANCE(548);
      END_STATE();
    case 472:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'f') ADVANCE(382);
      if (set_contains(sym_identifier_character_set_2, 776, lookahead)) ADVANCE(548);
      END_STATE();
    case 473:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'f') ADVANCE(397);
      if (set_contains(sym_identifier_character_set_2, 776, lookahead)) ADVANCE(548);
      END_STATE();
    case 474:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'g') ADVANCE(476);
      if (set_contains(sym_identifier_character_set_2, 776, lookahead)) ADVANCE(548);
      END_STATE();
    case 475:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'g') ADVANCE(471);
      if (set_contains(sym_identifier_character_set_2, 776, lookahead)) ADVANCE(548);
      END_STATE();
    case 476:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'h') ADVANCE(390);
      if (set_contains(sym_identifier_character_set_2, 776, lookahead)) ADVANCE(548);
      END_STATE();
    case 477:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'h') ADVANCE(461);
      if (set_contains(sym_identifier_character_set_2, 776, lookahead)) ADVANCE(548);
      END_STATE();
    case 478:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'i') ADVANCE(497);
      if (lookahead == 'l') ADVANCE(503);
      if (lookahead == 'r') ADVANCE(481);
      if (set_contains(sym_identifier_character_set_2, 776, lookahead)) ADVANCE(548);
      END_STATE();
    case 479:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'i') ADVANCE(542);
      if (lookahead == 'u') ADVANCE(511);
      if (set_contains(sym_identifier_character_set_2, 776, lookahead)) ADVANCE(548);
      END_STATE();
    case 480:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'i') ADVANCE(474);
      if (set_contains(sym_identifier_character_set_2, 776, lookahead)) ADVANCE(548);
      END_STATE();
    case 481:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'i') ADVANCE(453);
      if (set_contains(sym_identifier_character_set_2, 776, lookahead)) ADVANCE(548);
      END_STATE();
    case 482:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'i') ADVANCE(491);
      if (set_contains(sym_identifier_character_set_2, 776, lookahead)) ADVANCE(548);
      END_STATE();
    case 483:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'i') ADVANCE(521);
      if (set_contains(sym_identifier_character_set_2, 776, lookahead)) ADVANCE(548);
      END_STATE();
    case 484:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'i') ADVANCE(543);
      if (set_contains(sym_identifier_character_set_2, 776, lookahead)) ADVANCE(548);
      END_STATE();
    case 485:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'k') ADVANCE(546);
      if (set_contains(sym_identifier_character_set_2, 776, lookahead)) ADVANCE(548);
      END_STATE();
    case 486:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'k') ADVANCE(412);
      if (set_contains(sym_identifier_character_set_2, 776, lookahead)) ADVANCE(548);
      END_STATE();
    case 487:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'l') ADVANCE(503);
      if (set_contains(sym_identifier_character_set_2, 776, lookahead)) ADVANCE(548);
      END_STATE();
    case 488:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'l') ADVANCE(547);
      if (set_contains(sym_identifier_character_set_2, 776, lookahead)) ADVANCE(548);
      END_STATE();
    case 489:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'l') ADVANCE(501);
      if (set_contains(sym_identifier_character_set_2, 776, lookahead)) ADVANCE(548);
      END_STATE();
    case 490:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'l') ADVANCE(459);
      if (set_contains(sym_identifier_character_set_2, 776, lookahead)) ADVANCE(548);
      END_STATE();
    case 491:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'l') ADVANCE(389);
      if (set_contains(sym_identifier_character_set_2, 776, lookahead)) ADVANCE(548);
      END_STATE();
    case 492:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'l') ADVANCE(465);
      if (set_contains(sym_identifier_character_set_2, 776, lookahead)) ADVANCE(548);
      END_STATE();
    case 493:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'm') ADVANCE(508);
      if (set_contains(sym_identifier_character_set_2, 776, lookahead)) ADVANCE(548);
      END_STATE();
    case 494:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'm') ADVANCE(515);
      if (set_contains(sym_identifier_character_set_2, 776, lookahead)) ADVANCE(548);
      END_STATE();
    case 495:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'm') ADVANCE(400);
      if (set_contains(sym_identifier_character_set_2, 776, lookahead)) ADVANCE(548);
      END_STATE();
    case 496:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'n') ADVANCE(454);
      if (set_contains(sym_identifier_character_set_2, 776, lookahead)) ADVANCE(548);
      END_STATE();
    case 497:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'n') ADVANCE(434);
      if (set_contains(sym_identifier_character_set_2, 776, lookahead)) ADVANCE(548);
      END_STATE();
    case 498:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'n') ADVANCE(457);
      if (lookahead == 't') ADVANCE(470);
      if (set_contains(sym_identifier_character_set_2, 776, lookahead)) ADVANCE(548);
      END_STATE();
    case 499:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'n') ADVANCE(395);
      if (set_contains(sym_identifier_character_set_2, 776, lookahead)) ADVANCE(548);
      END_STATE();
    case 500:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'n') ADVANCE(393);
      if (set_contains(sym_identifier_character_set_2, 776, lookahead)) ADVANCE(548);
      END_STATE();
    case 501:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'o') ADVANCE(544);
      if (set_contains(sym_identifier_character_set_2, 776, lookahead)) ADVANCE(548);
      END_STATE();
    case 502:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'o') ADVANCE(495);
      if (set_contains(sym_identifier_character_set_2, 776, lookahead)) ADVANCE(548);
      END_STATE();
    case 503:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'o') ADVANCE(438);
      if (set_contains(sym_identifier_character_set_2, 776, lookahead)) ADVANCE(548);
      END_STATE();
    case 504:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'o') ADVANCE(405);
      if (set_contains(sym_identifier_character_set_2, 776, lookahead)) ADVANCE(548);
      END_STATE();
    case 505:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'o') ADVANCE(403);
      if (set_contains(sym_identifier_character_set_2, 776, lookahead)) ADVANCE(548);
      END_STATE();
    case 506:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'p') ADVANCE(417);
      if (set_contains(sym_identifier_character_set_2, 776, lookahead)) ADVANCE(548);
      END_STATE();
    case 507:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'p') ADVANCE(473);
      if (set_contains(sym_identifier_character_set_2, 776, lookahead)) ADVANCE(548);
      END_STATE();
    case 508:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'p') ADVANCE(398);
      if (set_contains(sym_identifier_character_set_2, 776, lookahead)) ADVANCE(548);
      END_STATE();
    case 509:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'p') ADVANCE(418);
      if (set_contains(sym_identifier_character_set_2, 776, lookahead)) ADVANCE(548);
      END_STATE();
    case 510:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'p') ADVANCE(488);
      if (lookahead == 'q') ADVANCE(539);
      if (lookahead == 't') ADVANCE(540);
      if (set_contains(sym_identifier_character_set_2, 776, lookahead)) ADVANCE(548);
      END_STATE();
    case 511:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'p') ADVANCE(384);
      if (set_contains(sym_identifier_character_set_2, 776, lookahead)) ADVANCE(548);
      END_STATE();
    case 512:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'p') ADVANCE(420);
      if (set_contains(sym_identifier_character_set_2, 776, lookahead)) ADVANCE(548);
      END_STATE();
    case 513:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'p') ADVANCE(385);
      if (lookahead == 'x') ADVANCE(568);
      if (set_contains(sym_identifier_character_set_2, 776, lookahead)) ADVANCE(548);
      END_STATE();
    case 514:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'p') ADVANCE(529);
      if (set_contains(sym_identifier_character_set_2, 776, lookahead)) ADVANCE(548);
      END_STATE();
    case 515:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'p') ADVANCE(419);
      if (set_contains(sym_identifier_character_set_2, 776, lookahead)) ADVANCE(548);
      END_STATE();
    case 516:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'q') ADVANCE(539);
      if (set_contains(sym_identifier_character_set_2, 776, lookahead)) ADVANCE(548);
      END_STATE();
    case 517:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'r') ADVANCE(449);
      if (set_contains(sym_identifier_character_set_2, 776, lookahead)) ADVANCE(548);
      END_STATE();
    case 518:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'r') ADVANCE(500);
      if (set_contains(sym_identifier_character_set_2, 776, lookahead)) ADVANCE(548);
      END_STATE();
    case 519:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'r') ADVANCE(445);
      if (set_contains(sym_identifier_character_set_2, 776, lookahead)) ADVANCE(548);
      END_STATE();
    case 520:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'r') ADVANCE(532);
      if (set_contains(sym_identifier_character_set_2, 776, lookahead)) ADVANCE(548);
      END_STATE();
    case 521:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'r') ADVANCE(467);
      if (set_contains(sym_identifier_character_set_2, 776, lookahead)) ADVANCE(548);
      END_STATE();
    case 522:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'r') ADVANCE(450);
      if (set_contains(sym_identifier_character_set_2, 776, lookahead)) ADVANCE(548);
      END_STATE();
    case 523:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'r') ADVANCE(415);
      if (set_contains(sym_identifier_character_set_2, 776, lookahead)) ADVANCE(548);
      END_STATE();
    case 524:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'r') ADVANCE(423);
      if (set_contains(sym_identifier_character_set_2, 776, lookahead)) ADVANCE(548);
      END_STATE();
    case 525:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 's') ADVANCE(469);
      if (set_contains(sym_identifier_character_set_2, 776, lookahead)) ADVANCE(548);
      END_STATE();
    case 526:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 't') ADVANCE(477);
      if (set_contains(sym_identifier_character_set_2, 776, lookahead)) ADVANCE(548);
      END_STATE();
    case 527:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 't') ADVANCE(463);
      if (set_contains(sym_identifier_character_set_2, 776, lookahead)) ADVANCE(548);
      END_STATE();
    case 528:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 't') ADVANCE(433);
      if (set_contains(sym_identifier_character_set_2, 776, lookahead)) ADVANCE(548);
      END_STATE();
    case 529:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 't') ADVANCE(484);
      if (set_contains(sym_identifier_character_set_2, 776, lookahead)) ADVANCE(548);
      END_STATE();
    case 530:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 't') ADVANCE(386);
      if (set_contains(sym_identifier_character_set_2, 776, lookahead)) ADVANCE(548);
      END_STATE();
    case 531:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 't') ADVANCE(512);
      if (set_contains(sym_identifier_character_set_2, 776, lookahead)) ADVANCE(548);
      END_STATE();
    case 532:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 't') ADVANCE(392);
      if (set_contains(sym_identifier_character_set_2, 776, lookahead)) ADVANCE(548);
      END_STATE();
    case 533:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 't') ADVANCE(406);
      if (set_contains(sym_identifier_character_set_2, 776, lookahead)) ADVANCE(548);
      END_STATE();
    case 534:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 't') ADVANCE(407);
      if (set_contains(sym_identifier_character_set_2, 776, lookahead)) ADVANCE(548);
      END_STATE();
    case 535:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 't') ADVANCE(464);
      if (set_contains(sym_identifier_character_set_2, 776, lookahead)) ADVANCE(548);
      END_STATE();
    case 536:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 't') ADVANCE(416);
      if (set_contains(sym_identifier_character_set_2, 776, lookahead)) ADVANCE(548);
      END_STATE();
    case 537:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'u') ADVANCE(498);
      if (set_contains(sym_identifier_character_set_2, 776, lookahead)) ADVANCE(548);
      END_STATE();
    case 538:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'u') ADVANCE(517);
      if (set_contains(sym_identifier_character_set_2, 776, lookahead)) ADVANCE(548);
      END_STATE();
    case 539:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'u') ADVANCE(483);
      if (set_contains(sym_identifier_character_set_2, 776, lookahead)) ADVANCE(548);
      END_STATE();
    case 540:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'u') ADVANCE(518);
      if (set_contains(sym_identifier_character_set_2, 776, lookahead)) ADVANCE(548);
      END_STATE();
    case 541:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'u') ADVANCE(522);
      if (set_contains(sym_identifier_character_set_2, 776, lookahead)) ADVANCE(548);
      END_STATE();
    case 542:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'v') ADVANCE(460);
      if (set_contains(sym_identifier_character_set_2, 776, lookahead)) ADVANCE(548);
      END_STATE();
    case 543:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'v') ADVANCE(462);
      if (set_contains(sym_identifier_character_set_2, 776, lookahead)) ADVANCE(548);
      END_STATE();
    case 544:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'w') ADVANCE(401);
      if (set_contains(sym_identifier_character_set_2, 776, lookahead)) ADVANCE(548);
      END_STATE();
    case 545:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'x') ADVANCE(569);
      if (set_contains(sym_identifier_character_set_2, 776, lookahead)) ADVANCE(548);
      END_STATE();
    case 546:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'y') ADVANCE(402);
      if (set_contains(sym_identifier_character_set_2, 776, lookahead)) ADVANCE(548);
      END_STATE();
    case 547:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'y') ADVANCE(408);
      if (set_contains(sym_identifier_character_set_2, 776, lookahead)) ADVANCE(548);
      END_STATE();
    case 548:
      ACCEPT_TOKEN(sym_identifier);
      if (set_contains(sym_identifier_character_set_2, 776, lookahead)) ADVANCE(548);
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
          (0x0b <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(551);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != '"' &&
          lookahead != '#') ADVANCE(552);
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
      if (set_contains(sym_identifier_character_set_2, 776, lookahead)) ADVANCE(548);
      END_STATE();
    case 569:
      ACCEPT_TOKEN(sym_max_keyword);
      if (lookahead == '-') ADVANCE(257);
      if (set_contains(sym_identifier_character_set_2, 776, lookahead)) ADVANCE(548);
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
      if (lookahead == '\\') SKIP(1);
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
          lookahead == ' ') SKIP(0);
      END_STATE();
    case 1:
      if (lookahead == '\n') SKIP(0);
      if (lookahead == '\r') SKIP(23);
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
      if (lookahead == '\n') SKIP(0);
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
  [5] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_lines, 0, 0, 0),
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
  [69] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_lines, 1, 0, 0),
  [71] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [73] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [75] = {.entry = {.count = 1, .reusable = true}}, SHIFT(101),
  [77] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_lines_repeat1, 2, 0, 0),
  [79] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_lines_repeat1, 2, 0, 0), SHIFT_REPEAT(4),
  [82] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_state_opt, 1, 0, 0),
  [84] = {.entry = {.count = 1, .reusable = true}}, SHIFT(34),
  [86] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_limit_spec, 2, 0, 7),
  [88] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_interface, 1, 0, 11),
  [90] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_state_opt_list_repeat1, 2, 0, 0),
  [92] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_state_opt_list_repeat1, 2, 0, 0), SHIFT_REPEAT(3),
  [95] = {.entry = {.count = 1, .reusable = true}}, SHIFT(51),
  [97] = {.entry = {.count = 1, .reusable = true}}, SHIFT(46),
  [99] = {.entry = {.count = 1, .reusable = true}}, SHIFT(47),
  [101] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_timeout_spec, 2, 0, 7),
  [103] = {.entry = {.count = 1, .reusable = true}}, SHIFT(53),
  [105] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_interface, 2, 0, 8),
  [107] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_state_opt_list, 2, 0, 0),
  [109] = {.entry = {.count = 1, .reusable = true}}, SHIFT(3),
  [111] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_state_opt, 4, 0, 13),
  [113] = {.entry = {.count = 1, .reusable = true}}, SHIFT(31),
  [115] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_state_opt_list, 1, 0, 0),
  [117] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_limit_list_repeat1, 2, 0, 0),
  [119] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_limit_list_repeat1, 2, 0, 0), SHIFT_REPEAT(14),
  [122] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_timeout_list, 1, 0, 0),
  [124] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
  [126] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_limit_list, 2, 0, 0),
  [128] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [130] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_state_opt, 5, 0, 13),
  [132] = {.entry = {.count = 1, .reusable = true}}, SHIFT(65),
  [134] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_interface_list, 1, 0, 0),
  [136] = {.entry = {.count = 1, .reusable = true}}, SHIFT(39),
  [138] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_state_opt, 2, 0, 0),
  [140] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_state_opt, 2, 0, 7),
  [142] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_timeout_list, 2, 0, 0),
  [144] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_if_bound_keyword, 1, 0, 0),
  [146] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_limit_list, 1, 0, 0),
  [148] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_interface_list, 2, 0, 0),
  [150] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_state_opt, 4, 0, 12),
  [152] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_timeout_list_repeat1, 2, 0, 0),
  [154] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_timeout_list_repeat1, 2, 0, 0), SHIFT_REPEAT(7),
  [157] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_floating_keyword, 1, 0, 0),
  [159] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_yes_keyword, 1, 0, 0),
  [161] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_no_keyword, 1, 0, 0),
  [163] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__reassemble_option, 2, 0, 0),
  [165] = {.entry = {.count = 1, .reusable = true}}, SHIFT(72),
  [167] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_interface_list_repeat1, 2, 0, 0),
  [169] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_interface_list_repeat1, 2, 0, 0), SHIFT_REPEAT(39),
  [172] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_option, 2, 0, 2),
  [174] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__debug_option, 2, 0, 0),
  [176] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__require_order_option, 2, 0, 0),
  [178] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_ruleset_optimizer, 1, 0, 0),
  [180] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__ruleset_optimization_option, 2, 0, 10),
  [182] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_lines_repeat1, 1, 0, 0),
  [184] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_line, 1, 0, 0),
  [186] = {.entry = {.count = 1, .reusable = true}}, SHIFT(83),
  [188] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_optimization_hint, 1, 0, 0),
  [190] = {.entry = {.count = 1, .reusable = true}}, SHIFT(81),
  [192] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__state_defaults_option, 2, 0, 0),
  [194] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__loginterface_option, 2, 0, 8),
  [196] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__state_policy_option, 2, 0, 0),
  [198] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__syncookies_option, 2, 0, 0),
  [200] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__loginterface_option, 2, 0, 0),
  [202] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__timeout_option, 2, 0, 0),
  [204] = {.entry = {.count = 1, .reusable = true}}, SHIFT(100),
  [206] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_ifspec, 3, 0, 0),
  [208] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__limit_option, 2, 0, 0),
  [210] = {.entry = {.count = 1, .reusable = false}}, SHIFT(73),
  [212] = {.entry = {.count = 1, .reusable = true}}, SHIFT(73),
  [214] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__reassemble_option, 3, 0, 0),
  [216] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__hostid_option, 2, 0, 7),
  [218] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__fingerprints_option, 2, 0, 6),
  [220] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__skip_option, 3, 0, 0),
  [222] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_ifspec, 1, 0, 0),
  [224] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__keep_counters_option, 1, 0, 0),
  [226] = {.entry = {.count = 1, .reusable = false}}, SHIFT(63),
  [228] = {.entry = {.count = 1, .reusable = false}}, SHIFT(66),
  [230] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__timeout_option, 4, 0, 0),
  [232] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__fail_policy_option, 2, 0, 0),
  [234] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__optimization_option, 2, 0, 9),
  [236] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__block_policy_option, 2, 0, 0),
  [238] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_option, 2, 0, 5),
  [240] = {.entry = {.count = 1, .reusable = true}}, SHIFT(52),
  [242] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_option, 2, 0, 4),
  [244] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string, 3, 0, 0),
  [246] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__limit_option, 4, 0, 0),
  [248] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_option, 2, 0, 3),
  [250] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_option, 2, 0, 1),
  [252] = {.entry = {.count = 1, .reusable = true}}, SHIFT(64),
  [254] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_option, 2, 0, 0),
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
  [292] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_timeout_type, 1, 0, 0),
  [294] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [296] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_comment, 2, 0, 0),
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

TS_PUBLIC const TSLanguage *tree_sitter_pfconf(void) {
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
