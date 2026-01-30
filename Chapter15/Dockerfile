FROM ubuntu:20.04

ARG DEBIAN_FRONTEND=noninteractive

RUN apt-get update && apt-get install -y \
	apt-utils \
	bison \
	ca-certificates \
	ccache \
	check \
	curl \
	flex \
	git \
	git-core \
	gperf \
	lcov \
	libncurses-dev \
	libusb-1.0-0-dev \
	make \
	ninja-build \
	python3 \
	unzip \
	wget \
	xz-utils \
	zip \
	python \
	python3-pip \
	python3-pexpect \
	python3-git \
	python3-jinja2 \
	libegl1-mesa \
	libsdl1.2-dev \
	locales \
	locales-all \
	chrpath \
	cpio \
	diffstat \
	gawk \
	texinfo \
	iputils-ping \
	python3-distutils \
	gcc-multilib \
	build-essential \
	socat \
	debianutils \
	pylint3 \
	xterm \
	vim \
	rsync \
	bc \
	tmux \
	git-lfs \
	liblz4-tool \
	zstd \
	ca-certificates \
	parted \
	&& apt-get autoremove -y \
	&& rm -rf /var/lib/apt/lists/*

ENV LC_ALL en_US.UTF-8
ENV LANG en_US.UTF-8
ENV LANGUAGE en_US.UTF-8

ARG host_user dev
ARG host_uid=1000
ARG host_gid=1000
RUN groupadd -g $host_gid $host_user && \
	useradd -g $host_gid -m -s /bin/bash -u $host_uid $host_user

USER dev

WORKDIR /home/dev

RUN mkdir /home/dev/bin
RUN curl https://storage.googleapis.com/git-repo-downloads/repo > /home/dev/bin/repo

RUN chmod a+x /home/dev/bin/repo
