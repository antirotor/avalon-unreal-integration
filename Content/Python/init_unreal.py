import unreal


@unreal.uclass()
class AvalonIntegration(unreal.AvalonPythonBridge):

    @unreal.ufunction(override=True)
    def RunInPython_Create(self):
        unreal.log_warning("Avalon: showing creator window")

    @unreal.ufunction(override=True)
    def RunInPython_Load(self):
        unreal.log_warning("Avalon: showing loader window")

    @unreal.ufunction(override=True)
    def RunInPython_Publish(self):
        unreal.log_warning("Avalon: showing publisher window")

    @unreal.ufunction(override=True)
    def RunInPython_Manage(self):
        unreal.log_warning("Avalon: showing manager window")

    @unreal.ufunction(override=True)
    def RunInPython_Workfiles(self):
        unreal.log_warning("Avalon: showing workfiles window")

    @unreal.ufunction(override=True)
    def RunInPython_ProjectManager(self):
        unreal.log_warning("Avalon: showing project manager window")
