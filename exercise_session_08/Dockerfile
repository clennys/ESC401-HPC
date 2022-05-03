FROM ubuntu:bionic

RUN apt-get update -q && \
	apt-get install -y -q \
		g++ \
		make \
		python-pip

RUN	pip install \
		numpy \
		tk \
		matplotlib

RUN DEBIAN_FRONTEND=noninteractive apt-get install -q -y --no-install-recommends \
		python-tk

COPY ./poisson_SERIAL /poisson_SERIAL
WORKDIR ./poisson_SERIAL
RUN make
CMD ./main && \
	cd output && \
	python plot.py

