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
# Example: system.hostname $a:string $!b:number
# regexps start with ^. If vector([]) dont end with $
# Följande hoppas över i XML översättningen: 

# system
system.boot                                          $dummie
system.hostname                                      $hostname
system.login.user[]                                  $!user
system.login.user[].uid                              $!user $uid:number
system.login.user[].class                            $!user $class
system.login.user[].authentication.password          $!user $password

system.boot.url[]                                    $!url $default $fallback # strange

# ipv4
ipv4.domain                                          $domain   # !?
ipv4.name-server[]                                   $!address:ipv4addr
ipv4.forwarding                                      $status:number
ipv4.route.static[]                                  $!prefix:ipv4prefix $!nexthop:ipv4addr $distance:number
ipv4.route.static.null[]                             $!prefix:ipv4prefix $reject $blackhole $distance:number
ipv4.arp[]                                           $!address:ipv4addr $!mac:macaddr
ipv4.as-path.access-list[]                           $!name $!action $!regexp:rest
ipv4.prefix-list[]                                   $!name
ipv4.prefix-list[].line[]                            $!name $!action $!prefix:ipv4prefix $le:number $ge:number $_SEQ:number
ipv4.prefix-list[].description                       $!name $description

# logging
logging.host[]                                       $!host:ipv4addr $protocol:string $port:number
logging.buffered                                     $rows:number $level:string
logging.trap                                         $level:string

# snmp
snmp.community.ro[]                                  $!community
snmp.community.rw[]                                  $!community
snmp.contact                                         $contact:rest
snmp.location                                        $location:rest

#ntp
ntp.server[]                                         $!address:ipv4addr
ntp.logging                                          $dummy:number # XXX


# access-list
#access-list[]                                        $!id:number
access-list[]                                        $!id:number $!action $!remark $!proto $!srcaddr:ipv4addr $!srcmask:ipv4addr $!dstaddr:ipv4addr $!dstmask:ipv4addr $exact_match $_SEQ:number
#ipv4.access-list[]                                   $!name
#ipv6.access-list[]                                   $!name

# interface
interface[]                                          $!name:string
interface[].unit[]				     $!name:string $!unit:number
interface[].unit[].inet.dhcp_client                  $!name:string $!unit:number $enabled:number
interface[].unit[].inet.address[]                    $!name:string $!unit:number $!prefix:ipv4prefix
interface[].unit[].description                       $!name:string $!unit:number $description:rest
interface[].unit[].dot1q                             $!name:string $!unit:number $vlan:number
interface[].unit[].tunnel.mode                       $!name:string $!unit:number $mode:string
interface[].unit[].tunnel.source                     $!name:string $!unit:number $source:ipv4addr
interface[].unit[].tunnel.destination                $!name:string $!unit:number $destination:ipv4addr
interface[].unit[].tunnel.csum                       $!name:string $!unit:number $csum:number
interface[].unit[].tunnel.tos                        $!name:string $!unit:number $tos:number
interface[].unit[].tunnel.ttl                        $!name:string $!unit:number $ttl:number
interface[].unit[].tunnel.key                        $!name:string $!unit:number $key:string
interface[].unit[].tunnel.nopmtu                     $!name:string $!unit:number $nopmtu:number
interface[].unit[].bandwidth                         $!name:string $!unit:number $bandwidth:number
interface[].unit[].link-detect                       $!name:string $!unit:number $link_detect:number
interface[].unit[].shutdown                          $!name:string $!unit:number $shutdown:number
interface[].unit[].ipv4.rp_filter                    $!name:string $!unit:number $status:number
interface[].unit[].ipv4.send_redirects               $!name:string $!unit:number $status:number
interface[].unit[].ipv4.proxy_arp                    $!name:string $!unit:number $status:number
interface[].unit[].ipv4.forwarding                   $!name:string $!unit:number $status:number
interface[].unit[].ipv4.shared_media                 $!name:string $!unit:number $status:number
interface[].unit[].ipv4.secure_redirects             $!name:string $!unit:number $status:number
interface[].unit[].ipv4.accept_source_route          $!name:string $!unit:number $status:number
interface[].unit[].ipv4.accept_redirects             $!name:string $!unit:number $status:number
interface[].unit[].ipv4.log_martians                 $!name:string $!unit:number $status:number
interface[].unit[].ospf.cost                         $!name:string $!unit:number $cost:number
interface[].unit[].ospf.network-type                 $!name:string $!unit:number $network_type
interface[].unit[].ospf.priority                     $!name:string $!unit:number $priority:number
interface[].unit[].rip.receive                       $!name:string $!unit:number $version:number
interface[].unit[].rip.send                          $!name:string $!unit:number $version:number
interface[].unit[].rip.split-horizon                 $!name:string $!unit:number $no_poisoned_reverse

# route-map
route-map[]                                          $!name
route-map[].line[]                                   $!name $!line:number $action 
route-map[].line[].call                              $!name $!line:number $action $route-map
route-map[].line[].description                       $!name $!line:number $action $description
route-map[].line[].match.as-path                     $!name $!line:number $action $as_path
route-map[].line[].match.interface                   $!name $!line:number $action $interface:string
route-map[].line[].match.ip.address                  $!name $!line:number $action $acl
route-map[].line[].match.ip.address.prefix-list      $!name $!line:number $action $prefix_list
route-map[].line[].match.ip.next-hop                 $!name $!line:number $action $acl
route-map[].line[].match.ip.next-hop.prefix-list     $!name $!line:number $action $prefix_list
route-map[].line[].match.ip.route-source             $!name $!line:number $action $acl
route-map[].line[].match.ip.route-source.prefix-list $!name $!line:number $action $prefix_list
route-map[].line[].match.metric                      $!name $!line:number $action $metric:number
route-map[].line[].on-match                          $!name $!line:number $action $op $goto:number
route-map[].line[].set.as-path.exclude               $!name $!line:number $action $as_path
route-map[].line[].set.as-path.prepend               $!name $!line:number $action $as_path
route-map[].line[].set.ip.next-hop                   $!name $!line:number $action $nexthop:ipv4addr
route-map[].line[].set.local-preference              $!name $!line:number $action $localpref:number
route-map[].line[].set.metric                        $!name $!line:number $action $metric:number
route-map[].line[].set.metric-type                   $!name $!line:number $action $metric_type
route-map[].line[].set.origin                        $!name $!line:number $action $origin
route-map[].line[].set.originator-id                 $!name $!line:number $action $originator_id
route-map[].line[].set.pathlimit.ttl                 $!name $!line:number $action $ttl:number
route-map[].line[].set.tag                           $!name $!line:number $action $route_tag
route-map[].line[].set.weight                        $!name $!line:number $action $weight:number
route-map[].line[].continue                          $!name $!line:number $action $goto:number

# router.router-id
router.router-id                                     $routerid:ipv4addr

# router.bgp
router.bgp                                           $as:number
router.bgp.router-id                                 $routerid:ipv4addr
router.bgp.log-neighbor-changes                      $status:number
router.bgp.always-compare-med                        $status:number
router.bgp.default.local-preference                  $local_preference:number
router.bgp.enforce-first-as                          $status:number
router.bgp.deterministic-med                         $status:number
router.bgp.graceful-restart                          $stalepath_time:number
router.bgp.network.import-check                      $status:number
router.bgp.dampening                                 $half_life:number $reuse:number $suppress:number $max_suppress:number
router.bgp.network[]                                 $!prefix:ipv4prefix $route_map
router.bgp.aggregate-address[]                       $!prefix:ipv4prefix
router.bgp.redistribute.connected                    $metric:number $route_map
router.bgp.redistribute.kernel                       $metric:number $route_map
router.bgp.redistribute.ospf                         $metric:number $route_map
router.bgp.redistribute.rip                          $metric:number $route_map
router.bgp.redistribute.static                       $metric:number $route_map
router.bgp.neighbor[]                                $!neighbor:ipv4addr
router.bgp.neighbor[].remote-as                      $!neighbor:ipv4addr $remote_as:number
router.bgp.neighbor[].local-as                       $!neighbor:ipv4addr $localas:number $no_prepend
router.bgp.neighbor[].description                    $!neighbor:ipv4addr $description:rest
router.bgp.neighbor[].shutdown                       $!neighbor:ipv4addr
router.bgp.neighbor[].password                       $!neighbor:ipv4addr $password
router.bgp.neighbor[].passive                        $!neighbor:ipv4addr
router.bgp.neighbor[].ebgp-multihop                  $!neighbor:ipv4addr $maxhops:number
router.bgp.neighbor[].update-source                  $!neighbor:ipv4addr $source:ipv4addr
router.bgp.neighbor[].advertisement-interval         $!neighbor:ipv4addr $interval
router.bgp.neighbor[].timers                         $!neighbor:ipv4addr $keepalive:number $holdtime:number
router.bgp.neighbor[].timers.connect                 $!neighbor:ipv4addr $connect:number
router.bgp.neighbor[].weight                         $!neighbor:ipv4addr $weight:number
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
router.bgp.distance.bgp                              $external:number $internal:number $local:number
router.bgp.distance[]                                $!prefix:ipv4prefix $distance $acl

# router.ospf
router.ospf                                          $instance:number
router.ospf.router-id                                $routerid:ipv4addr
router.ospf.abr-type                                 $abr_type
router.ospf.log-adjacency-changes                    $status:number $detail
router.ospf.compatible                               $rfc1583:number
router.ospf.auto-cost.reference-bandwidth            $bandwidth:number
router.ospf.timers.throttle.spf                      $delay:number $initial_hold:number $max_hold:number
router.ospf.max-metric.router-lsa.on-startup         $on_startup:number
router.ospf.max-metric.router-lsa.on-shutdown        $on_shutdown:number
router.ospf.max-metric.router-lsa.on-administrative  $administrative:number
router.ospf.refresh-timer                            $timer:number
router.ospf.redistribute.bgp                         $metric:number $metric_type $route_map 
router.ospf.redistribute.connected                   $metric:number $metric_type $route_map 
router.ospf.redistribute.isis                        $metric:number $metric_type $route_map 
router.ospf.redistribute.kernel                      $metric:number $metric_type $route_map 
router.ospf.redistribute.rip                         $metric:number $metric_type $route_map 
router.ospf.redistribute.static                      $metric:number $metric_type $route_map 
router.ospf.passive-interface[]                      $!interface:string
router.ospf.network[]                                $!prefix:ipv4prefix $area:ipv4addr
router.ospf.area[]                                   $!area:ipv4addr
router.ospf.area[].auth                              $!area:ipv4addr $auth
router.ospf.area[].shortcut                          $!area:ipv4addr $mode
router.ospf.area[].stub                              $!area:ipv4addr $stub:number $no_summary
router.ospf.area[].default-cost                      $!area:ipv4addr $cost:number
router.ospf.area[].export-list                       $!area:ipv4addr $export_list
router.ospf.area[].import-list                       $!area:ipv4addr $import_list
router.ospf.area[].nssa                              $!area:ipv4addr $translate $no_summary
router.ospf.area[].range[]                           $!area:ipv4addr $!range:ipv4prefix $not_advertise $cost:number $substitute:ipv4prefix
router.ospf.neighbor[]                               $!neighbor:ipv4addr $priority:number $poll_interval:number
router.ospf.default-metric                           $metric:number
router.ospf.distribute-list[]                        $!direction $!protocol $acl 
router.ospf.default-information.originate            $always $metric:number $metric_type $route_map
router.ospf.distance                                 $distance:number
router.ospf.distance.ospf                            $inter_area:number $external:number $intra_area:number
router.ospf.capability                               $opaque:number

# router.rip
router.rip                                           $instance:number
router.rip.default-information                       $status:number
router.rip.default-metric                            $metric:number
router.rip.distance                                  $distance:number
router.rip.distance.prefix[]                         $!prefix:ipv4prefix $distance:number $acl
router.rip.distribute-list[]                         $!direction $!interface:string $acl
router.rip.distribute-list.prefix[]                  $!direction $!interface:string $prefix:ipv4prefix
router.rip.neighbor[]                                $!neighbor:ipv4addr
router.rip.network.prefix[]                          $!prefix:ipv4prefix
router.rip.network.interface[]                       $!interface:string
router.rip.offset-list[]                             $!direction $!interface:string $acl $metric:number 
router.rip.passive-interface[]                       $!interface:string
router.rip.redistribute.bgp                         $metric:number $route_map 
router.rip.redistribute.connected                   $metric:number $route_map 
router.rip.redistribute.isis                        $metric:number $route_map 
router.rip.redistribute.kernel                      $metric:number $route_map 
router.rip.redistribute.ospf                        $metric:number $route_map 
router.rip.redistribute.static                      $metric:number $route_map 
router.rip.route[]                                   $!prefix:ipv4prefix
router.rip.version                                   $version:number
router.rip.timers.basic                              $update:number $timeout:number $garbage:number
router.rip.route-map[]                               $!direction $!interface:string $route_map 
