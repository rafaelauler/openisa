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
# successfully completed. It will take another round of 5+ hours.
RUN ./crossbuild_arm.sh

# The next command runs x86 experiments. It will take circa 3 hours. Comment it
# out if you want to later edit scripts to run experiments less than 10 times
# (which is used for statistical rigor) in order to run them faster.
RUN ./run.sh

CMD /bin/bash
