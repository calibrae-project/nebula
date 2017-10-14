# Instructions for building the Nebula server

In the following document are the instructions for setting up a development environment for working on the code in this repository. It creates an Ubuntu 16.04 chroot, mounts your home folder inside it, and leaves you as root. If you follow the instructions below, you will be able to make changes to the code and relatively quickly test them by using the makefile in the cmake build folder.

## Prerequisites

You must have debootstrap and schroot installed on your system. This applies equally whether you are running anything other than ubuntu 16 and 14. It was developed on Antergos linux and should work on any variety of Arch also, as well as probably it will work on any linux whatsoever, if you can install these.

## Build process

First, create the bootstrap by running the script schroot.sh which you can find
in the root of the repository. 

```
./schroot
```

This will create a chroot environment in your home folder in a directory called 'nebula', and configure schroot with the settings to find it in the correct location.

Next, as instructed by this first script, you must do the following:

```
./login
```

This will put you inside a chroot, in a bindmounted directory inside a fresh home folder based on your existing username, as root based on Ubuntu 16.04, and then run the following script to prepare the environment for building:

```
./schroot-prep
```

Once you have run `schroot-prep` one time the chroot environment will not need to be prepared again. Exit the chroot with <Ctrl-D>, then after this you get into the chroot thus:

```
./login
```

and when you are inside the chroot:

```
su <yourusername>
```

Then you can:

```
mkdir build
cd build
cmake -DCMAKE_BUILD_TYPE=Release ..
make -j$(nproc) nebula
make -j$(nproc) cli_wallet
# optional
make install  # defaults to /usr/local
```

or, alternatively,

```
./build-nebula
```

From there, you can then test whatever changes you have made to the code.
