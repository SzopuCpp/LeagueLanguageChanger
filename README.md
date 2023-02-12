# LeagueLanguageChanger
**Works only on Windows**

## How to compile  
Download [nlohmann-json](https://github.com/nlohmann/json) by [vcpkg](https://vcpkg.io/en/index.html)

## How to use
Create json file named `LlcConfig.json` in `.exe` file directory:
```{
   "LanguageSettings": {
      "language": "en_US"
   },
   "Paths": {
      "LeagueClient": "path\\to\\your\\LeagueClient.exe"
   }
}
```
and set `"LeagueClient"` to the path to your `LeagueClient.exe`.
**Remember about double backslash (`\\`) instead of single!**
