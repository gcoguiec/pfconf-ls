/// <reference types="tree-sitter-cli/dsl" />
// @ts-check

module.exports = grammar({
  name: 'pfconf',
  word: $ => $.identifier,
  externals: () => [],
  extras: $ => [$.comment, /\s/, /\\\r?\n/],
  rules: {
    lines: $ => repeat($.line),
    line: $ => choice($.option),

    comment: () => seq('#', /.*/),

    option: $ =>
      seq(
        $.set_keyword,
        choice(
          $._reassemble_option,
          $._optimization_option,
          $._ruleset_optimization_option,
          $._timeout_option,
          $._limit_option,
          $._loginterface_option,
          $._hostid_option,
          $._block_policy_option,
          $._fail_policy_option,
          $._require_order_option,
          $._fingerprints_option,
          $._state_policy_option,
          $._debug_option,
          $._skip_option,
          $._state_defaults_option,
          $._keep_counters_option,
          $._syncookies_option
        )
      ),
    _reassemble_option: $ =>
      seq(
        $.reassemble_keyword,
        choice($.yes_keyword, $.no_keyword),
        optional($.no_df_keyword)
      ),
    _optimization_option: $ =>
      seq($.optimization_keyword, field('hint', $.optimization_hint)),
    _ruleset_optimization_option: $ =>
      seq(
        $.ruleset_optimization_keyword,
        field('optimizer', $.ruleset_optimizer)
      ),
    _timeout_option: $ =>
      seq(
        $.timeout_keyword,
        choice($.timeout_spec, seq('{', $.timeout_list, '}'))
      ),
    _limit_option: $ =>
      seq($.limit_keyword, choice($.limit_spec, seq('{', $.limit_list, '}'))),
    _loginterface_option: $ =>
      seq(
        $.loginterface_keyword,
        choice(field('interface', $.identifier), 'none')
      ),
    _hostid_option: $ =>
      seq($.hostid_keyword, field('number', choice($.number, $.hex_number))),
    _block_policy_option: $ =>
      seq($.block_policy_keyword, choice($.drop_keyword, $.return_keyword)),
    _fail_policy_option: $ =>
      seq($.fail_policy_keyword, choice($.drop_keyword, $.return_keyword)),
    _require_order_option: $ =>
      seq($.require_order_keyword, choice('yes', 'no')),
    _fingerprints_option: $ =>
      seq($.fingerprints_keyword, field('filename', $.string)),
    _state_policy_option: $ =>
      seq($.state_policy_keyword, choice('if-bound', 'floating')),
    _debug_option: $ =>
      seq($.debug_keyword, choice('none', 'urgent', 'misc', 'loud')),
    _skip_option: $ => seq($.skip_keyword, $.on_keyword, $.ifspec),
    _state_defaults_option: $ =>
      seq($.state_defaults_keyword, $.state_opt_list),
    _keep_counters_option: $ => seq($.keepcounters_keyword),
    _syncookies_option: $ =>
      seq($.syncookies_keyword, choice('never', 'adaptative', 'always')),

    optimization_hint: () =>
      choice(
        'normal',
        'satellite',
        'high-latency',
        'conservative',
        'aggressive'
      ),
    ruleset_optimizer: () => choice('none', 'basic', 'profile'),

    timeout_list: $ => list1($.timeout_spec),
    timeout_spec: $ => seq($.timeout_type, field('number', $.number)),
    timeout_type: () =>
      choice(
        'tcp.first',
        'tcp.opening',
        'tcp.established',
        'tcp.closing',
        'tcp.finwait',
        'tcp.closed',
        'tcp.tsdiff',
        'sctp.opening',
        'sctp.established',
        'sctp.closing',
        'sctp.closed',
        'udp.first',
        'udp.single',
        'udp.multiple',
        'icmp.first',
        'icmp.error',
        'other.first',
        'other.single',
        'other.multiple',
        'frag',
        'interval',
        'adaptive.start',
        'adaptive.end',
        'src.track'
      ),

    limit_list: $ => list1($.limit_spec),
    limit_spec: $ =>
      seq(
        choice('states', 'src-nodes', 'frags', 'table-entries'),
        field('number', $.number)
      ),

    ifspec: $ => choice($.interface, seq('{', $.interface_list, '}')),
    interface_list: $ => list1($.interface),
    interface: $ =>
      seq(optional($.not_operator), field('interface', $.identifier)),

    state_opt_list: $ => list1($.state_opt),
    state_opt: $ =>
      choice(
        seq($.max_keyword, field('number', $.number)),
        $.no_sync_keyword,
        $.timeout_spec,
        $.sloppy_keyword,
        seq(
          $.source_track_keyword,
          optional(choice($.rule_keyword, $.global_keyword))
        ),
        seq($.max_src_nodes_keyword, field('number', $.number)),
        seq($.max_src_states_keyword, field('number', $.number)),
        seq($.max_src_conn_keyword, field('number', $.number)),
        seq(
          $.max_src_conn_rate_keyword,
          field('number', $.number),
          '/',
          field('number', $.number)
        ),
        seq(
          $.overload_keyword,
          '<',
          field('string', $.identifier),
          '>',
          optional($.flush_keyword)
        ),
        $.if_bound_keyword,
        $.floating_keyword
      ),

    // https://unicode.org/reports/tr31/#Table_Lexical_Classes_for_Identifiers
    identifier: () => /[_\p{XID_Start}][_\p{XID_Continue}]*/,
    string: () => seq('"', /[^"\n]*/, '"'),
    number: () => /\d+/,
    hex_number: () => /0x[0-9a-fA-F]+/,

    not_operator: () => '!',

    all_keyword: () => 'all',
    allow_opts_keyword: () => 'allow-opts',
    altq_keyword: () => 'altq',
    anchor_keyword: () => 'anchor',
    antispoof_keyword: () => 'antispoof',
    any_keyword: () => 'any',
    bandwidth_keyword: () => 'bandwidth',
    binat_keyword: () => 'binat',
    binat_anchor_keyword: () => 'binat-anchor',
    bitmask_keyword: () => 'bitmask',
    block_keyword: () => 'block',
    block_policy_keyword: () => 'block-policy',
    bridge_to_keyword: () => 'bridge-to',
    buckets_keyword: () => 'buckets',
    cbq_keyword: () => 'cbq',
    code_keyword: () => 'code',
    codelq_keyword: () => 'codelq',
    debug_keyword: () => 'debug',
    divert_reply_keyword: () => 'divert-reply',
    divert_to_keyword: () => 'divert-to',
    dnpipe_keyword: () => 'dnpipe',
    dnqueue_keyword: () => 'dnqueue',
    drop_keyword: () => 'drop',
    dup_to_keyword: () => 'dup-to',
    ether_keyword: () => 'ether',
    fail_policy_keyword: () => 'fail-policy',
    fairq_keyword: () => 'fairq',
    fastroute_keyword: () => 'fastroute',
    file_keyword: () => 'file',
    fingerprints_keyword: () => 'fingerprints',
    flags_keyword: () => 'flags',
    floating_keyword: () => 'floating',
    flush_keyword: () => 'flush',
    for_keyword: () => 'for',
    fragment_keyword: () => 'fragment',
    from_keyword: () => 'from',
    global_keyword: () => 'global',
    group_keyword: () => 'group',
    hfsc_keyword: () => 'hfsc',
    hogs_keyword: () => 'hogs',
    hostid_keyword: () => 'hostid',
    icmp_type_keyword: () => 'icmp-type',
    icmp6_type_keyword: () => 'icmp6-type',
    if_bound_keyword: () => 'if-bound',
    in_keyword: () => 'in',
    include_keyword: () => 'include',
    inet_keyword: () => 'inet',
    inet6_keyword: () => 'inet6',
    interval_keyword: () => 'interval',
    keep_keyword: () => 'keep',
    keepcounters_keyword: () => 'keepcounters',
    l3_keyword: () => 'l3',
    label_keyword: () => 'label',
    limit_keyword: () => 'limit',
    linkshare_keyword: () => 'linkshare',
    load_keyword: () => 'load',
    log_keyword: () => 'log',
    loginterface_keyword: () => 'loginterface',
    map_e_portset_keyword: () => 'map-e-portset',
    match_keyword: () => 'match',
    max_keyword: () => 'max',
    max_mss_keyword: () => 'max-mss',
    max_src_conn_keyword: () => 'max-src-conn',
    max_src_conn_rate_keyword: () => 'max-src-conn-rate',
    max_src_nodes_keyword: () => 'max-src-nodes',
    max_src_states_keyword: () => 'max-src-states',
    min_ttl_keyword: () => 'min-ttl',
    modulate_keyword: () => 'modulate',
    nat_keyword: () => 'nat',
    nat_anchor_keyword: () => 'nat-anchor',
    no_keyword: () => 'no',
    no_df_keyword: () => 'no-df',
    no_route_keyword: () => 'no-route',
    no_sync_keyword: () => 'no-sync',
    on_keyword: () => 'on',
    optimization_keyword: () => 'optimization',
    os_keyword: () => 'os',
    out_keyword: () => 'out',
    overload_keyword: () => 'overload',
    pass_keyword: () => 'pass',
    pflow_keyword: () => 'pflow',
    port_keyword: () => 'port',
    prio_keyword: () => 'prio',
    priority_keyword: () => 'priority',
    priq_keyword: () => 'priq',
    probability_keyword: () => 'probability',
    proto_keyword: () => 'proto',
    qlimit_keyword: () => 'qlimit',
    queue_keyword: () => 'queue',
    quick_keyword: () => 'quick',
    random_keyword: () => 'random',
    random_id_keyword: () => 'random-id',
    rdr_keyword: () => 'rdr',
    rdr_anchor_keyword: () => 'rdr-anchor',
    realtime_keyword: () => 'realtime',
    reassemble_keyword: () => 'reassemble',
    reply_to_keyword: () => 'reply-to',
    require_order_keyword: () => 'require-order',
    return_keyword: () => 'return',
    return_icmp_keyword: () => 'return-icmp',
    return_icmp6_keyword: () => 'return-icmp6',
    return_rst_keyword: () => 'return-rst',
    ridentifier_keyword: () => 'ridentifier',
    round_robin_keyword: () => 'round-robin',
    route_keyword: () => 'route',
    route_to_keyword: () => 'route-to',
    rtable_keyword: () => 'rtable',
    rule_keyword: () => 'rule',
    ruleset_optimization_keyword: () => 'ruleset-optimization',
    scrub_keyword: () => 'scrub',
    self_keyword: () => 'self',
    set_keyword: () => 'set',
    set_tos_keyword: () => 'set-tos',
    skip_keyword: () => 'skip',
    sloppy_keyword: () => 'sloppy',
    source_hash_keyword: () => 'source-hash',
    source_track_keyword: () => 'source-track',
    state_keyword: () => 'state',
    state_defaults_keyword: () => 'state-defaults',
    state_policy_keyword: () => 'state-policy',
    static_port_keyword: () => 'static-port',
    sticky_address_keyword: () => 'sticky-address',
    syncookies_keyword: () => 'syncookies',
    synproxy_keyword: () => 'synproxy',
    table_keyword: () => 'table',
    tag_keyword: () => 'tag',
    tagged_keyword: () => 'tagged',
    target_keyword: () => 'target',
    tbrsize_keyword: () => 'tbrsize',
    timeout_keyword: () => 'timeout',
    to_keyword: () => 'to',
    tos_keyword: () => 'tos',
    ttl_keyword: () => 'ttl',
    upperlimit_keyword: () => 'upperlimit',
    urpf_failed_keyword: () => 'urpf-failed',
    user_keyword: () => 'user',
    yes_keyword: () => 'yes'
  }
});

/**
 * Creates a rule to match a list with one or more rules separated by a comma.
 *
 * @param  {RuleOrLiteral} rule
 *
 * @returns {SeqRule}
 */
function list1(rule) {
  return seq(rule, repeat(seq(',', rule)));
}
