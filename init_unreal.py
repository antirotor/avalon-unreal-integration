import unreal
from avalon import api
from avalon import unreal as avalon_unreal


@unreal.uclass()
class AvalonIntegration(unreal.AvalonPythonBridge):

    @unreal.ufunction(override=True)
    def RunInPython_Create(self):
        unreal.log_warning("Avalon: showing creator window")
        avalon_unreal.show_creator()

    @unreal.ufunction(override=True)
    def RunInPython_Load(self):
        unreal.log_warning("Avalon: showing loader window")
        avalon_unreal.show_loaders()

    @unreal.ufunction(override=True)
    def RunInPython_Publish(self):
        unreal.log_warning("Avalon: showing publisher window")
        avalon_unreal.show_publish()

    @unreal.ufunction(override=True)
    def RunInPython_Manage(self):
        unreal.log_warning("Avalon: showing manager window")
        avalon_unreal.show_manager()

    @unreal.ufunction(override=True)
    def RunInPython_Workfiles(self):
        unreal.log_warning("Avalon: showing workfiles window")
        avalon_unreal.show_workfiles()

    @unreal.ufunction(override=True)
    def RunInPython_ProjectManager(self):
        unreal.log_warning("Avalon: showing project manager window")
        avalon_unreal.show_projectManager()
