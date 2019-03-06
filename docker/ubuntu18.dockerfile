FROM ubuntu:18.04

# Instala Base
RUN apt-get update
RUN apt-get install -y python-pip python-dev

# Instala Ansible
RUN pip install ansible==2.7.8.0

# Copia tudo para o container
COPY . /vss-core-ubuntu18
WORKDIR /vss-core-ubuntu18

# Adiciona permissão de execução dos shellscripts
RUN chmod +x /vss-core-ubuntu18/configure.sh
RUN chmod +x /vss-core-ubuntu18/entrypoint.sh
RUN chmod +x /vss-core-ubuntu18/scripts/protos.sh
RUN chmod +x /vss-core-ubuntu18/scripts/base.sh

# Executa a instalação na criação dos containers
RUN /vss-core-ubuntu18/configure.sh development

# Script executado no docker run
ENTRYPOINT ["/vss-core-ubuntu18/entrypoint.sh"]