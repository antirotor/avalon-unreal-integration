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


@unreal.uclass()
class AvalonPythonLibs(unreal.AvalonLib):

    @unreal.ufunction(params=[str, unreal.LinearColor, bool])
    def set_folder_color(self, path, color, force=False):
        """
        This method sets color on folder in Content Browser. Unfortunately
        there is no way to refresh Content Browser so new color isn't applied
        immediately. They are saved to config file and appears correctly
        only after Editor is restarted.

        Usage:
            AvalonColorHelper().set_folder_color(
                "/Game/Path", unreal.LinearColor(a=1.0, r=1.0, g=0.5, b=0)
            )
        """
        self.c_set_folder_color(path, color, force)

    @unreal.ufunction(rets=unreal.AssetContainer, params=[str, str])
    def create_avalon_container(self, path, name):
        factory = unreal.AssetContainerFactory()
        tools = unreal.AssetToolsHelpers().get_asset_tools()
        asset = tools.create_asset(name, path, None, factory)
        return asset
