# See here for image contents: https://github.com/microsoft/vscode-dev-containers/tree/v0.238.1/containers/cpp/.devcontainer/base.Dockerfile

# [Choice] Debian / Ubuntu version (use Debian 11, Ubuntu 18.04/22.04 on local arm64/Apple Silicon): debian-11, debian-10, ubuntu-22.04, ubuntu-20.04, ubuntu-18.04
ARG VARIANT="bullseye"
FROM mcr.microsoft.com/vscode/devcontainers/cpp:0-${VARIANT}

RUN sed -i 's/^# deb-src/deb-src/g' /etc/apt/sources.list

RUN apt-get update && export DEBIAN_FRONTEND=noninteractive \
     && apt-get -y install --no-install-recommends \
     && apt install -y libqt5*-dev qt5*-dev \
     gn \
     mc \
     htop

# OpenMind deps
RUN apt install -y libboost-all-dev libxss-dev libx11-dev libxcb-screensaver0-dev ocl-icd-opencl-dev libopengl-dev freeglut3-dev libleveldb-dev libvulkan-dev liblz4-dev libfmt-dev librocksdb-dev libpython3-all-dev libopencl-clang-dev libtbb-dev

# Karts deps
#RUN apt build-dep -y qt5-quick-demos
#RUN apt build-dep -y qtcreator
RUN apt install -y qtquickcontrols2-5-dev

# VScode parser
RUN apt install -y clang clangd lld

RUN apt install -y libtbb-dev
