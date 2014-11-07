# 
# Database spec file
# CVS Version: $Id: datamodel.spec,v 1.8 2014/01/23 21:22:54 benny Exp $ 
#
# Copyright (C) 2009-2013 Olof Hagsand and Benny Holmgren
#
# This file is part of ROST.
#
# ROST is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 3 of the License, or
# (at your option) any later version.
#
#  ROST is distributed in the hope that it will be useful,
#  but WITHOUT ANY WARRANTY; without even the implied warranty of
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#  GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along wth ROST; see the file COPYING.  If not, see
# <http://www.gnu.org/licenses/>.
#
# Syntax: 
# <line> ::= <key> <var>*
# <var>  ::= $[!]<name>[:<type>] (string is default type)
# Example: system.hostname $a:string $!b:int32
# regexps start with ^. If vector([]) dont end with $
# Följande hoppas över i XML översättningen: 

# system
system.boot                                          $dummie
system.hostname                                      $hostname
system.login.user[]                                  $!user
system.login.user[].uid                              $!user $uid:int32
system.login.user[].class                            $!user $class
system.login.user[].authentication.password          $!user $password

system.boot.url[]                                    $!url $default $fallback # strange

# ipv4
ipv4.domain                                          $domain   # !?
ipv4.name-server[]                                   $!address:ipv4addr
ipv4.forwarding                                      $status:int32
ipv4.route.static[]                                  $!prefix:ipv4prefix $!nexthop:ipv4addr $distance:int32
ipv4.route.static.null[]                             $!prefix:ipv4prefix $reject $blackhole $distance:int32
ipv4.arp[]                                           $!address:ipv4addr $!mac:macaddr
ipv4.as-path.access-list[]                           $!name $!action $!regexp:rest
ipv4.prefix-list[]                                   $!name
ipv4.prefix-list[].line[]                            $!name $!action $!prefix:ipv4prefix $le:int8 $ge:int8 $_SEQ:int32
ipv4.prefix-list[].description                       $!name $description

# logging
logging.host[]                                       $!host:ipv4addr $protocol:string $port:int32
logging.buffered                                     $rows:int32 $level:string
logging.trap                                         $level:string

# snmp
snmp.community.ro[]                                  $!community
snmp.community.rw[]                                  $!community
snmp.contact                                         $contact:rest
snmp.location                                        $location:rest

#ntp
ntp.server[]                                         $!address:ipv4addr
ntp.logging                                          $dummy:int32 # XXX


# access-list
ipv4.access-list.standard[]                          $!id:uint32
ipv4.access-list.standard[].remark                   $!id:uint32 $remark:rest
ipv4.access-list.standard[].line[]                   $!id:uint32 $_SEQ:int32 $!action:string $!src:ipv4addr $!srcmask:ipv4addr

ipv4.access-list.standard.named[]                    $!name:string
ipv4.access-list.standard.named[].remark             $!name:string $remark:rest
ipv4.access-list.standard.named[].line[]             $!name:string $_SEQ=int32 $!action $!src:ipv4prefix $!exact_match:bool

ipv4.access-list.extended[]                          $!id:uint32
ipv4.access-list.extended[].remark                   $!id:uint32 $remark:rest
ipv4.access-list.extended[].line[]                   $!id:uint32 $_SEQ:int32 $!action:string $!protocol $!src:ipv4prefix $!srcmask:ipv4addr $!dst:ipv4addr $!dstmask:ipv4addr

#ipv4.access-list[]                                   $!name
#ipv6.access-list[]                                   $!name

# interface
interface[]                                          $!name:string
interface[].unit[]				     $!name:string $!unit:int32
interface[].unit[].inet.dhcp_client                  $!name:string $!unit:int32 $enabled:int32
interface[].unit[].inet.address[]                    $!name:string $!unit:int32 $!prefix:ipv4prefix
interface[].unit[].description                       $!name:string $!unit:int32 $description:rest
interface[].unit[].dot1q                             $!name:string $!unit:int32 $vlan:int32
interface[].unit[].tunnel.mode                       $!name:string $!unit:int32 $mode:string
interface[].unit[].tunnel.source                     $!name:string $!unit:int32 $source:ipv4addr
interface[].unit[].tunnel.destination                $!name:string $!unit:int32 $destination:ipv4addr
interface[].unit[].tunnel.csum                       $!name:string $!unit:int32 $csum:int32
interface[].unit[].tunnel.tos                        $!name:string $!unit:int32 $tos:int32
interface[].unit[].tunnel.ttl                        $!name:string $!unit:int32 $ttl:int32
interface[].unit[].tunnel.key                        $!name:string $!unit:int32 $key:string
interface[].unit[].tunnel.nopmtu                     $!name:string $!unit:int32 $nopmtu:int32
interface[].unit[].bandwidth                         $!name:string $!unit:int32 $bandwidth:int32
interface[].unit[].link-detect                       $!name:string $!unit:int32 $link_detect:int32
interface[].unit[].shutdown                          $!name:string $!unit:int32 $shutdown:int32
interface[].unit[].ipv4.rp_filter                    $!name:string $!unit:int32 $status:int32
interface[].unit[].ipv4.send_redirects               $!name:string $!unit:int32 $status:int32
interface[].unit[].ipv4.proxy_arp                    $!name:string $!unit:int32 $status:int32
interface[].unit[].ipv4.forwarding                   $!name:string $!unit:int32 $status:int32
interface[].unit[].ipv4.shared_media                 $!name:string $!unit:int32 $status:int32
interface[].unit[].ipv4.secure_redirects             $!name:string $!unit:int32 $status:int32
interface[].unit[].ipv4.accept_source_route          $!name:string $!unit:int32 $status:int32
interface[].unit[].ipv4.accept_redirects             $!name:string $!unit:int32 $status:int32
interface[].unit[].ipv4.log_martians                 $!name:string $!unit:int32 $status:int32
interface[].unit[].ospf.cost                         $!name:string $!unit:int32 $cost:int32
interface[].unit[].ospf.network-type                 $!name:string $!unit:int32 $network_type
interface[].unit[].ospf.priority                     $!name:string $!unit:int32 $priority:int32
interface[].unit[].rip.receive                       $!name:string $!unit:int32 $version:int32
interface[].unit[].rip.send                          $!name:string $!unit:int32 $version:int32
interface[].unit[].rip.split-horizon                 $!name:string $!unit:int32 $no_poisoned_reverse

# route-map
route-map[]                                          $!name
route-map[].line[]                                   $!name $!line:int32 $action 
route-map[].line[].call                              $!name $!line:int32 $action $route-map
route-map[].line[].description                       $!name $!line:int32 $action $description
route-map[].line[].match.as-path                     $!name $!line:int32 $action $as_path
route-map[].line[].match.interface                   $!name $!line:int32 $action $interface:string
route-map[].line[].match.ip.address                  $!name $!line:int32 $action $acl
route-map[].line[].match.ip.address.prefix-list      $!name $!line:int32 $action $prefix_list
route-map[].line[].match.ip.next-hop                 $!name $!line:int32 $action $acl
route-map[].line[].match.ip.next-hop.prefix-list     $!name $!line:int32 $action $prefix_list
route-map[].line[].match.ip.route-source             $!name $!line:int32 $action $acl
route-map[].line[].match.ip.route-source.prefix-list $!name $!line:int32 $action $prefix_list
route-map[].line[].match.metric                      $!name $!line:int32 $action $metric:int32
route-map[].line[].on-match                          $!name $!line:int32 $action $op $goto:int32
route-map[].line[].set.as-path.exclude               $!name $!line:int32 $action $as_path
route-map[].line[].set.as-path.prepend               $!name $!line:int32 $action $as_path
route-map[].line[].set.ip.next-hop                   $!name $!line:int32 $action $nexthop:ipv4addr
route-map[].line[].set.local-preference              $!name $!line:int32 $action $localpref:int32
route-map[].line[].set.metric                        $!name $!line:int32 $action $metric:int32
route-map[].line[].set.metric-type                   $!name $!line:int32 $action $metric_type
route-map[].line[].set.origin                        $!name $!line:int32 $action $origin
route-map[].line[].set.originator-id                 $!name $!line:int32 $action $originator_id
route-map[].line[].set.pathlimit.ttl                 $!name $!line:int32 $action $ttl:int32
route-map[].line[].set.tag                           $!name $!line:int32 $action $route_tag
route-map[].line[].set.weight                        $!name $!line:int32 $action $weight:int32
route-map[].line[].continue                          $!name $!line:int32 $action $goto:int32

# router.router-id
router.router-id                                     $routerid:ipv4addr

# router.bgp
router.bgp                                           $as:int32
router.bgp.router-id                                 $routerid:ipv4addr
router.bgp.log-neighbor-changes                      $status:int32
router.bgp.always-compare-med                        $status:int32
router.bgp.default.local-preference                  $local_preference:int32
router.bgp.enforce-first-as                          $status:int32
router.bgp.deterministic-med                         $status:int32
router.bgp.graceful-restart                          $stalepath_time:int32
router.bgp.network.import-check                      $status:int32
router.bgp.dampening                                 $half_life:int32 $reuse:int32 $suppress:int32 $max_suppress:int32
router.bgp.network[]                                 $!prefix:ipv4prefix $route_map
router.bgp.aggregate-address[]                       $!prefix:ipv4prefix
router.bgp.redistribute.connected                    $metric:int32 $route_map
router.bgp.redistribute.kernel                       $metric:int32 $route_map
router.bgp.redistribute.ospf                         $metric:int32 $route_map
router.bgp.redistribute.rip                          $metric:int32 $route_map
router.bgp.redistribute.static                       $metric:int32 $route_map
router.bgp.neighbor[]                                $!neighbor:ipv4addr
router.bgp.neighbor[].remote-as                      $!neighbor:ipv4addr $remote_as:int32
router.bgp.neighbor[].local-as                       $!neighbor:ipv4addr $localas:int32 $no_prepend
router.bgp.neighbor[].description                    $!neighbor:ipv4addr $description:rest
router.bgp.neighbor[].shutdown                       $!neighbor:ipv4addr
router.bgp.neighbor[].password                       $!neighbor:ipv4addr $password
router.bgp.neighbor[].passive                        $!neighbor:ipv4addr
router.bgp.neighbor[].ebgp-multihop                  $!neighbor:ipv4addr $maxhops:int32
router.bgp.neighbor[].update-source                  $!neighbor:ipv4addr $source:ipv4addr
router.bgp.neighbor[].advertisement-interval         $!neighbor:ipv4addr $interval
router.bgp.neighbor[].timers                         $!neighbor:ipv4addr $keepalive:int32 $holdtime:int32
router.bgp.neighbor[].timers.connect                 $!neighbor:ipv4addr $connect:int32
router.bgp.neighbor[].weight                         $!neighbor:ipv4addr $weight:int32
router.bgp.neighbor[].next-hop-self                  $!neighbor:ipv4addr
router.bgp.neighbor[].remove-private-as              $!neighbor:ipv4addr
router.bgp.neighbor[].default-originate              $!neighbor:ipv4addr $route_map
router.bgp.neighbor[].soft-reconfiguration.inbound   $!neighbor:ipv4addr
router.bgp.neighbor[].prefix-list.in                 $!neighbor:ipv4addr $prefix_list
router.bgp.neighbor[].prefix-list.out                $!neighbor:ipv4addr $prefix_list
router.bgp.neighbor[].route-map.in                   $!neighbor:ipv4addr $route_map
router.bgp.neighbor[].route-map.out                  $!neighbor:ipv4addr $route_map
router.bgp.neighbor[].distribute-list.in             $!neighbor:ipv4addr $acl
router.bgp.neighbor[].distribute-list.out            $!neighbor:ipv4addr $acl
router.bgp.neighbor[].filter-list.in                 $!neighbor:ipv4addr $acl
router.bgp.neighbor[].filter-list.out                $!neighbor:ipv4addr $acl
router.bgp.neighbor[].activate                       $!neighbor:ipv4addr
router.bgp.distance.bgp                              $external:int32 $internal:int32 $local:int32
router.bgp.distance[]                                $!prefix:ipv4prefix $distance $acl

# router.ospf
router.ospf                                          $instance:int32
router.ospf.router-id                                $routerid:ipv4addr
router.ospf.abr-type                                 $abr_type
router.ospf.log-adjacency-changes                    $status:int32 $detail
router.ospf.compatible                               $rfc1583:int32
router.ospf.auto-cost.reference-bandwidth            $bandwidth:int32
router.ospf.timers.throttle.spf                      $delay:int32 $initial_hold:int32 $max_hold:int32
router.ospf.max-metric.router-lsa.on-startup         $on_startup:int32
router.ospf.max-metric.router-lsa.on-shutdown        $on_shutdown:int32
router.ospf.max-metric.router-lsa.on-administrative  $administrative:int32
router.ospf.refresh-timer                            $timer:int32
router.ospf.redistribute.bgp                         $metric:int32 $metric_type $route_map 
router.ospf.redistribute.connected                   $metric:int32 $metric_type $route_map 
router.ospf.redistribute.isis                        $metric:int32 $metric_type $route_map 
router.ospf.redistribute.kernel                      $metric:int32 $metric_type $route_map 
router.ospf.redistribute.rip                         $metric:int32 $metric_type $route_map 
router.ospf.redistribute.static                      $metric:int32 $metric_type $route_map 
router.ospf.passive-interface[]                      $!interface:string
router.ospf.network[]                                $!prefix:ipv4prefix $area:ipv4addr
router.ospf.area[]                                   $!area:ipv4addr
router.ospf.area[].auth                              $!area:ipv4addr $auth
router.ospf.area[].shortcut                          $!area:ipv4addr $mode
router.ospf.area[].stub                              $!area:ipv4addr $stub:int32 $no_summary
router.ospf.area[].default-cost                      $!area:ipv4addr $cost:int32
router.ospf.area[].export-list                       $!area:ipv4addr $export_list
router.ospf.area[].import-list                       $!area:ipv4addr $import_list
router.ospf.area[].nssa                              $!area:ipv4addr $translate $no_summary
router.ospf.area[].range[]                           $!area:ipv4addr $!range:ipv4prefix $not_advertise $cost:int32 $substitute:ipv4prefix
router.ospf.neighbor[]                               $!neighbor:ipv4addr $priority:int32 $poll_interval:int32
router.ospf.default-metric                           $metric:int32
router.ospf.distribute-list[]                        $!direction $!protocol $acl 
router.ospf.default-information.originate            $always $metric:int32 $metric_type $route_map
router.ospf.distance                                 $distance:int32
router.ospf.distance.ospf                            $inter_area:int32 $external:int32 $intra_area:int32
router.ospf.capability                               $opaque:int32

# router.rip
router.rip                                           $instance:int32
router.rip.default-information                       $status:int32
router.rip.default-metric                            $metric:int32
router.rip.distance                                  $distance:int32
router.rip.distance.prefix[]                         $!prefix:ipv4prefix $distance:int32 $acl
router.rip.distribute-list[]                         $!direction $!interface:string $acl
router.rip.distribute-list.prefix[]                  $!direction $!interface:string $prefix:ipv4prefix
router.rip.neighbor[]                                $!neighbor:ipv4addr
router.rip.network.prefix[]                          $!prefix:ipv4prefix
router.rip.network.interface[]                       $!interface:string
router.rip.offset-list[]                             $!direction $!interface:string $acl $metric:int32 
router.rip.passive-interface[]                       $!interface:string
router.rip.redistribute.bgp                         $metric:int32 $route_map 
router.rip.redistribute.connected                   $metric:int32 $route_map 
router.rip.redistribute.isis                        $metric:int32 $route_map 
router.rip.redistribute.kernel                      $metric:int32 $route_map 
router.rip.redistribute.ospf                        $metric:int32 $route_map 
router.rip.redistribute.static                      $metric:int32 $route_map 
router.rip.route[]                                   $!prefix:ipv4prefix
router.rip.version                                   $version:int32
router.rip.timers.basic                              $update:int32 $timeout:int32 $garbage:int32
router.rip.route-map[]                               $!direction $!interface:string $route_map 
