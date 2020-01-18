# Avalon Unreal Integration plugin

This is plugin for Unreal Editor, creating menu for [Avalon](https://github.com/getavalon) tools to run.

This is basically workaround - Unreal cannot create main menu through its Python and the only way I found so far is by using Unreal Editor plugin to do this job and then call functions in python to do the real work.

## How does this work

Plugin is creating basic menu items in **Window/Avalon** section  of Unreal Editor main menu. Clicking on those menu items is calling callbacks that are declared in c++ but needs to be implemented during Unreal Editor startup in `Plugins/Avalon/Content/Python/init_unreal.py` - this should be executed by Unreal Editor automatically.
