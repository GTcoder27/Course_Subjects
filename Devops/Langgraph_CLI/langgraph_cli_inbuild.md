# Required files in the project 
-langgraph.json 
-pyproject.toml



# runs the docker image locally as a containerized service (requires paid license)
langgraph up

# install langgraph-cli 
pip install langgraph-cli[inmem]

# make pyproject.toml
# read pyproject.toml
pip install -e .    // it will automatically detect and read pyproject.toml from current directory (-e is editable mode)

# runs your agent as a local REST API server with hot reloading and studio UI 
langgraph dev

# build a dockerfile 
langgraph dockerfile Dockerfile

# packages your agent into a self contained docker image 
langgraph build
langgraph build -t <image_name>
langgraph build -t chat-agent:local     // chat-agent is image name and local is the tag that identifies image version  






# sequence to deploy 
1. make project 
2. make pyproject.toml
3. make langgraph.json
4. go to project folder
5. pip install -e .
6. langgraph dev
7. server has stared now














###### pyproject.toml #######
[build-system]
requires = ["setuptools>=68"]
build-backend = "setuptools.build_meta"

[project]
name = "agent_app1"
version = "0.1.0"
reqires-python = ">=3.12"

dependencies = [
"langgraph"
"langchain"
"langchain-google-genai"
"python-dotenv"
]

[tool.setuptools.package.find]
where = ["src"]

[tool.setuptools.package-dir]
"" = "src"
###### pyproject.toml end #######



###### langgraph.json #######
{
    "dependencies":["."],
    "graph":{
        "chat_agent":"./src/graph/graph.py:graph"
    },
    "python-version":"3.14",
    "env":".env",
    "image_distro":"wolfi"

}
###### langgraph.json end #######

###### docker-compose.yml ########
version: '0.1' 

services:
  redis:
    image: redis:6
    ports:
      - "6379:6379"
  postgres:
    image: postgres:16
    environment:
      POSTGRES_DB: langgraph
      POSTGRES_USER: langgraph
      POSTGRES_PASSWORD: langgraph
    ports:
      - "5432:5432"
    healthcheck:
      test: ["CMD-SHELL", "pg_isready -U langgraph"]
      interval: 5s
      timeout: 5s
      retries: 5
    volumes:
      - langgraph-data:/var/lib/postgresql/data
  chat-agent:
    image: chat-agent:local
    ports:
      - "8000:8000"
    env_file:
      - .env
    environment:
      REDIS_URI: redis://redis:6379
      DATABASE_URI: postgres://langgraph:langgraph@postgres:5432/langgraph?sslmode=disable
    volumes:
      - ~/.aws:/root/.aws:ro
    depends_on:
      redis:
        condition: service_started
      postgres:
        condition: service_healthy
volumes:
  langgraph-data:
###### docker-compose.yml end #######


# versioning
version = "0.1.0"                   // MAJOR.MINOR.PATCH       
MAJOR = breaking changes 
MINOR = new features that are backward compatible 
PATCH = bug fixes and small improvements

# in pyproject.toml tells to look in "src" folder for packages which nested folders contain "__init__.py" file 
[tool.setuptools.packages.find]
where = ["src"]

# in pyproject.toml tells to change the import path for packages from "."(current directory) to "./src/" 
[tool.setuptools.package-dir]
"" = "src"







