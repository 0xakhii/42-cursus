arch=$(uname -a)
phcpu=$(lscpu | grep -m 1 "CPU(s)" | cut -d ":" -f 2 | tr -d " ")
vcpu=$(cat /proc/cpuinfo | grep processor | wc -l)
fram=$(free -m | awk '$1 == "Mem:" {print $2}')
uram=$(free -m | awk '$1 == "Mem:" {print $3}')
pram=$(free | awk '$1 == "Mem:" {printf("%.2f"), $3/$2*100}')
udisk=$(df --total -h | awk '$1 == "total" {printf("%d/%dGb (%.2f%%)", $3 * 1024, $2, ($3 * 100) / $2)}')
ucpu=$(top -bn1 | grep '^%Cpu' | awk '{printf("%.2f%%", $2 + $4)}')
lboot=$(who -b | awk '{print $3 " " $4}')
clvm=$(lsblk | grep -c "lvm")
ulvm=$(if [ $clvm -eq 0 ]; then echo no; else echo yes; fi)
ctcp=$(netstat | grep tcp | wc -l)
ulog=$(users | tr  " " "\n" | wc -l)
ipaddr=$(hostname -I)
macaddr=$(ip link | awk '$1 == "link/ether" {print $2}')
scmd=$(cat /var/log/sudo/sudo.log | grep "COMMAND" | wc -l)
wall "	#Architecture: $arch
	#CPU physical : $phcpu
	#vCPU : $vcpu
	#Memory Usage: $uram/${fram}MB ($pram%)
	#Disk Usage: $udisk
	#CPU load: $ucpu
	#Last boot: $lboot
	#LVM use: $ulvm
	#Connection TCP : $ctcp ESTABLISHED
	#User log: $ulog
	#Network: IP $ipaddr ($macaddr)
	#Sudo : $scmd cmd"
