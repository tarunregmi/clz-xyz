This is a simple docker setup to `initialize/build/run/publish` .NET application.

Build and start the docker container using Docker Compose:

```bash
# build and start docker container
docker compose up --build -d

# connect to the container's terminal
docker compose exec app bash
```

Now that we're inside the container’s terminal, we can create and run our .NET project. `.NET` provides a wide variety of templates for creating different types of applications, libraries, and other projects. Each type of application or library has its own template, which can be created using the `dotnet new` command.

Here’s a quick summary of the some common templates:

| Command               | Template Name          | Description                                |
| --------------------- | ---------------------- | ------------------------------------------ |
| `dotnet new console`  | Console App            | Simple command-line application            |
| `dotnet new web`      | Web App (ASP.NET Core) | Basic web application                      |
| `dotnet new webapp`   | Web App (ASP.NET Core) | Web app with Razor Pages & authentication  |
| `dotnet new webapi`   | Web API (ASP.NET Core) | RESTful Web API                            |
| `dotnet new mvc`      | MVC App (ASP.NET Core) | MVC-based web application                  |
| `dotnet new classlib` | Class Library          | Library of reusable classes                |
| `dotnet new worker`   | Worker Service         | Background worker service                  |
| `dotnet new maui`     | .NET MAUI App          | Multi-platform app (iOS, Android, Windows) |

We can see a complete list of all available templates on our local machine using command:

```bash
dotnet new --list
```

Command to install and uninstall these template:

```bash
# to install
# dotnet new install <template-package-name>
dotnet new install Microsoft.Maui.Templates

# to uninstall
# dotnet new uninstall <template-package-name>
dotnet new uninstall Microsoft.Maui.Templates
```

---

Now, lets understand how to build, run and publish any .NET project using following simple `hello-world` cli project.

```bash
# create a new .NET project
dotnet new console -n "hello-world"

cd hello-world

# build the project
dotnet build

# run the project
dotnet run

# publish the application as a Self-Contained executable
# <runtime_identifier>: linux-x64 | win-x64 | osx-x64
dotnet publish -c Release -r <runtime_identifier> --self-contained
# dotnet publish -c Release -r linux-x64 --self-contained true /p:PublishSingleFile=true
```

---

### Configure PostgreSQL Database:

```bash
dotnet add package Npgsql.EntityFrameworkCore
```

Install and configure Npgsql:

```bash
dotnet add package Npgsql.EntityFrameworkCore.PostgreSQL
```

Open `appsettings.json` file and add code (replace if exist):

```json
"ConnectionStrings": {
    "DefaultConnection": "Host=database;Port=5445;Database=dotnet;Username=postgres;Password=password;"
  }
```

```bash
# generate migration file
dotnet ef migrations add <mgName>

# update database
dotnet ef database update
```
