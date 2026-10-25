


# pull the image
docker pull redis

# show all docker images 
docker images 

# show all running processes or containers
docker ps
docker ps -a     # all running and not running containers 

# make a container using image and run the container
docker run redis
docker run -d redis                             // runs in detatched mode
docker run -p 6379:6379 redis                   // port mapping -p HOST_PORT:CONTAINER_PORT
docker run --name redis_container1 redis        // give a readable name to the container
docker run -it ubuntu                           // opens in interactive shell 
docker run --env-file .env redis
docker run -e POSTGRES_PASSWORD=secret postgres // for environment variables 
docker run --rm redis                           // automatically removes the container ones it exits 
--network NAME                                  // connects the container to a specific user defined network
-v SRC:DST                                      // mounts a volume (bind mount OR named volume)
-t                                              // tags the command which is used for debugging

# stop the container
docker stop redis_container1

# remove container 
docker rm redis_container1

# execute a command in already running container
docker exec -it ubuntu_container_1 bash 

# stream live logs 
docker logs -f redis_container1 

# cpu and memory usage 
docker stats            // cpu and memory usage 
docker system df        // shows docker disk usage
docker system prune     // remove unused data 

# execute multiple commands using &&
example-> docker stop redis_container1 && docker rm redis_container1    

# docker volume
docker volume create agent-state    // create new volume
docker volume ls                    // list all docker volumes
docker volume inspect agent-state   // displays detailed configuration and metadata
docker volume rm agent-state        // remove volume

# bind mount (maps a folder on host machine directly into container) (remove in production)
-v $(pwd):/app
example->  docker run -d -p 8080:8080 -v "$(pwd):/app" my-node-app

# named volumne (is the storage docker manages for you which is hidden from your host file system) (keep in production)
-v agent-state:/data
example->  docker run -d --name my-agent -v agent-state:/data my-agent-image


### Formating instructions for Dockerfile
FROM python:3.11  // sets base image and must always be the first line 
WORKDIR         // sets the working directory insode the container (create if it doesn't exist)
COPY            // brings files from host machine to image 
RUN             // execute a shell command during the build 
ENV             // environment variables into an image,  (only for non secret configuration like PYTHONUNBUFFERED=1)
                    never use for API keys 
EXPOSE          // which port the application uses when the container will run(used for metadata only) 
                    actual port allocation is done by "docker run -p 8000:8000 redis"  
.dockerignore   // just like .gitignore



# build a docker image using dockerfile  
docker build -t app_build1 ./langgraph_app


# create a network 
docker network create app_network1 

# run docker compose file 
# after running docker compose file it automatically create a network
docker compose up -d
docker compose up --build                       // Build the image and start the container
docker compose up --build -d                    // Run in the background
docker compose logs -f agent-app                // view logs
docker compose down                             // Stop and remove the container
docker compose ps                               // shows the processes running in the container of that image 
docker compose restart agent-app                // to restart the app
docker compose exec redis redis-cli FLUSHALL    // remove whole redis cache 
docker compose down                             // stops containers, keeps mongoDB data safe(safe stop)
docker compose down -v                          // also deletes the volume - all history gone(full reset)


###### Docker compose file #######
build: ./frontend           // build the image form the Dockerfile present in the frontend folder
image: redis:7-alpine       // use this prebuilt image from dockerhub
container_name: container1      
ports: "8000:8000"
env_file: .env
volumes: 
depends_on:                 // ensures specified services start before the current service starts
networks:                   // controls which docker networks the container joins
restart: unless-stopped     // automatically restarts container if it crashes, but keeps it stopped if manually stopped by the user

###### compose.yaml #######
services:
    agent: 
        build: .
        ports:
            - "8000:8000"
        environment:
            LOG_LEVEL: info
        depends_on:
            - postgres
    postgres:
        image: postgres:16
        volumes:
            - db-data:/var/lib/postgres/data
volumes:
    db-data
###### compose.yaml end ######
###### Docker compose file end ######



###### Docker Langgraph-cli #######
# pull the langgraph-api image
docker pull langchain/langgraph-api:rc-py3.11-wolfi

# generate a Dockerfile using langchain-cli from your langgraph.json config
pip install -U "langgraph-cli[inmen]"
langgraph dockerfile Dockerfile           

# build and launch the stack 
docker compose up --build -d 
###### Docker langgraph-cli end ###### 







# NETWORK 
docker network create net1
docker network ls
docker network inspect net1
docker network rm net1















###### .dockerignore ######
# Python cache
__pycache__/
*.py[cod]
*.pyo
# Virtual environments
.venv/
venv/
env/
# Environment variables and secrets
.env
.env.*
# Git
.git/
.gitignore
# IDE files
.vscode/
.idea/
# Testing and coverage
.pytest_cache/
.coverage
htmlcov/
# OS files
.DS_Store
###### .dockerignore end ########

