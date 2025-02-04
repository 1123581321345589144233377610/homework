FROM ubuntu:22.04
RUN apt-get update && apt-get install -y \
    gcc \
    clang \
    make \
    cmake \
    build-essential \
    git
WORKDIR /work
COPY . /work
CMD ["bash"]
