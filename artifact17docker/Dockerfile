# Build this with docker build -t rafaelauler/artifact17 .

FROM debian:jessie
MAINTAINER Rafael Auler <rafaelauler@gmail.com>
RUN apt-get update && apt-get install -y \
  build-essential \
  bzip2 \
  cmake \
  gawk \
  git \
  gnuplot-nox \
  libc6-dev-i386 \
  lib32z1 \
  linux-tools \
  ninja-build \
  python \
  r-base \
  time \
  wget
RUN mkdir /openisa
WORKDIR /openisa
COPY build.sh build.sh

# The next command takes 5+ hours to finish. Comment it out if you want to run
# this later, maybe leaving the most expensive programs out by editing the build
# scripts. Keep in mind that all subsequent RUN instructions depend on this one,
# so if you want to comment this out, you should also do it with the others.
RUN ./build.sh

COPY run.sh run.sh
COPY crossbuild_arm.sh crossbuild_arm.sh

# The next command builds ARM binaries. It depends on "build.sh" being
# successfully completed. It will take another round of 4+ hours.
RUN ./crossbuild_arm.sh

CMD /bin/bash

# Once the image is ready, create a container with
# # docker run -v /host/folder:/mnt/shared -t -i rafaelauler/artifact17
# In the container, type "./run.sh" to run the experiments on x86.
# Change "/host/folder" above to a valid folder in your system. Whenever you copy
# a file to /mnt/shared inside the container, it will be copied to this folder.
# Use this folder to copy the experimental results (after run.sh finishes):
# # cp /openisa/oitools/openisa/spec/testes-x86/*.pdf /mnt/shared
# And also to copy the programs to run in ARM:
# # cp /openisa/bundle-arm.tar.bz2 /mnt/shared
# Transfer the bundle-arm.tar.bz2 file to an ARM platform to run the experiments
# on an ARM. Once in the ARM platform, run the script "measure_arm.sh".
# Results for ARM will be available in similar PDF files as those from x86.
