# Born2beRoot 1337

• How a virtual machine works?

A VM is **a virtualized instance of a computer that can perform almost all of the same functions as a computer, including running applications and operating systems**
. Virtual machines run on a physical machine and access computing resources from software called a hypervisor.

• The basic differences between Rocky and Debian, and the choice of operating system?

Rocky

- Rocky is more stable than Debian and supports enterprise applications.
- Does not have an upgrade path.
- It comes with many security in-built features that help protect from cyber-attacks using SELinux. It helps to reduce the vulnerabilities of privilege escalation attacks.

Debian

- Released and supported by the community
- Debian has more software/packages available.
- Debian community members still maintain it.
- It comes with an easy installation package.

• The purpose of virtual machines?

The main purpose of VMs is to operate multiple operating systems at the same time, from the same piece of hardware. Without virtualization, operating multiple systems — like Windows and Linux — would require two separate physical units.

• The difference between aptitude and apt?

Apt and Aptitude are both package managers but aptitude is more upgraded than apt, Aptitude is like a graphical interface of apt, also apt is a low level package manager that is good for digging deeper in this field.

• What APPArmor is?

AppArmor provides **Mandatory Access Control (MAC) security**. For example, if an installed application can take photos by accessing the camera application, but the administrator denies this privilege, the application will not be able to access the camera application. If a vulnerability occurs (some of the restricted tasks are performed), AppArmor blocks the application so that the damage does not spread to the rest of the system.

• Check that the UFW service is started?

**UFW**  is a software application responsible for ensuring that the system administrator can **manage iptables in a simple way**
. UFW provides us with an interface to modify the firewall of our device ****without compromising security. Once we have UFW installed, we can choose which ports we want to allow connections. Check UFW status via `sudo ufw status`.

• Check that the SSH service is started?

SSH, also known as Secure Shell , is **a network protocol that gives users a secure way to access a computer over an unsecured network**. Check SSH status via `sudo service ssh status`.

• Check that the chosen operating system is Debian?

`uname -a`.

• Check that a user with the login of the student is present on the virtual machine: `users`

• Check that the user has been added and that it belongs to the

"sudo" and "user42" groups.`getent group user42` `getent group sudo`

## **User**

1-Create new user via `sudo adduser <username>`
2-Create a group named "evaluating”:`sudo addgroup evaluating`

3-Assign it to this user:`sudo adduser <username> evaluating`.

4-Check that this user belongs to the "evaluating" group: `getent group evaluating`.

5-How I was able to set up the strong password rules requested in the subject on my virtual machine? `sudo vim /etc/login.defs` and I changed PASS_MAX_DAYS, PASS_MIN_DAYS, PASS_WARN_AGE

6-Advantages and disadvantages of using strong password policy : 

- they are very hard to guess for human.
- the combination are easy to guess for machines.

## **Hostname and partitions**

- Check the hostname of the machine :`uname -a` or `hostnamectl`
- Modify this hostname:`sudo hostnamectl set-hostname "imad"` (reboot to change).
- View the partitions for this virtual machine: `lsblk`
- LVM : is short for Logic Volume Manager and its purpose is to gather a whole bunch of hard disks into a group of logic volumes that you have more control over and flexibility.

## **SUDO**

- Add user to *sudo* group via `adduser <username> sudo`.
- The value and operation of sudo : **superuser do** is a command that runs commands without a need to change your identity. Depending on your settings in the /etc/sudoers.d/ file `sudo vim /etc/sudoers.d/`

## **UFW / Firewalld**

- Check that the "UFW” is installed : `dpkg -l | grep ufw`
- What UFW is and the value of using it : is a frontend for managing firewall rules in Linux, UFW is used through the command line, and aims to make firewall configuration easy , it stops all connection til we give theme the permission
- Check UFW status via `sudo ufw status`.
- Delete a rule :`sudo ufw delete NUM` NUM is the number of rule in UFW status table

## **SSH**

- Check that it is working properly : `dpkg -l | grep ssh`
- What is SSH ?  or secure shell, is an encrypted protocol used to administer and communicate with servers.
