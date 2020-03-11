import unreal

avalon_detected = True
try:
    from avalon import api
    from avalon import unreal as avalon_unreal
except ImportError as exc:
    avalon_detected = False
    unreal.log_error("Avalon: cannot load avalon [ {} ]".format(exc))

if avalon_detected:
    api.install(avalon_unreal)


@unreal.uclass()
class AvalonIntegration(unreal.AvalonPythonBridge):

    @unreal.ufunction(override=True)
    def RunInPython_Create(self):
        unreal.log_warning("Avalon: showing creator window")
        if avalon_detected:
            avalon_unreal.show_creator()

    @unreal.ufunction(override=True)
    def RunInPython_Load(self):
        unreal.log_warning("Avalon: showing loader window")
        if avalon_detected:
            avalon_unreal.show_loader()

    @unreal.ufunction(override=True)
    def RunInPython_Publish(self):
        unreal.log_warning("Avalon: showing publisher window")
        if avalon_detected:
            avalon_unreal.show_publisher()

    @unreal.ufunction(override=True)
    def RunInPython_Manage(self):
        unreal.log_warning("Avalon: showing manager window")
        if avalon_detected:
            avalon_unreal.show_manager()

    @unreal.ufunction(override=True)
    def RunInPython_Workfiles(self):
        # not implemented yet
        unreal.log_warning("Avalon: showing workfiles window")

    @unreal.ufunction(override=True)
    def RunInPython_ProjectManager(self):
        unreal.log_warning("Avalon: showing project manager window")
        if avalon_detected:
            avalon_unreal.show_project_manager()
