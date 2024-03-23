# use command exec
exec {'pkill':
  command   => 'pkill -f killmenow',
  path      => '/bin:/usr/bin',
}
