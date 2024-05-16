### Interactive Map Project

## Tool install

# Frontend
0. Install Visual Studio Code (I used it as IDE)
1. Install Node.js
2. Open GitHub repo in Visual Studio
2.1 Through terminal go into folder frontend-developement
2.2 run npm install
2.3 run npm start
2.4 errors might hint to what other packages need to be installed

The frontend should run on it's own

# Backend
1. install mariaDB 11.3.2, the database -> https://mariadb.org/download/?t=mariadb&p=mariadb&r=11.3.2
2. create a database with a root access on it, and adapt the connection string in our code : server=@ip; uid=root; pwd=[password]; database=[database name]
3. install .net, version 6.0, it was the latest long term support version at the time we started the project -> https://dotnet.microsoft.com/en-us/download/dotnet - when the installer asks you which workload to install, select ASP.NET and web development workload in the Web & Cloud section - these are the official instructions if something doesnt work https://learn.microsoft.com/en-us/dotnet/core/install/windows?tabs=net80 , it also has instructions for linux
4. install visual studio 2022, the ide for .net -> https://visualstudio.microsoft.com/vs/ - if you prefer you can also use jetbrains rider, but this is the ide i use and the ide i can help you with
5. go to github, copy the url and clone the repo (git clone url in git bash)
6. open visual studio
7. in visual studio, Tools -> NuGet package manager -> package manager console
8. in the package manager console run Update-Database (if any bug, try to specify the location of the terminal to InteractiveMapProject[...].DB
9. for testing, you could create a file.sql(or use the dummy-data.sql at the root of the project) script to initialize the database with dummy data, and use : "source /path/to/file.sql" from the sql command prompt to run the script
file.
10. create a free geoapify account and get you api key -> https://www.geoapify.com/
11. go to visual studio, right click on InteractiveMapProject.API in the solution explorer (right) and select Manage user secrets
12. paste this:
{
  "Geoapify": {
    "ApiKey": "your api key"
  }
}
13. now you can run your backend by clicking on the green triangle in the visual studio, it will opet a swagger window where you can test the endpoints.
