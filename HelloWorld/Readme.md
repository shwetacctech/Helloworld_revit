# Revit Plugin: ElementIdReader
The ElementIdReader Revit plugin is a simple external command that retrieves and displays the Element IDs of selected elements in the active Revit document. The plugin is set to run in read-only mode.

# Overview
The plugin consists of a single external command class:

# Command Class (Command): Implements the IExternalCommand interface and serves as the main external command. It retrieves the Element IDs of selected elements in the active document and displays the information in a TaskDialog.
+ Usage
+ Installation:

+ Compile the project to generate the plugin DLL.
+ Copy the DLL to the Revit Addins folder (e.g., C:\ProgramData\Autodesk\Revit\Addins{Revit Version}).
+ Run the Plugin:

+ Open Revit.
+ Select one or more elements in the Revit model.
+ Navigate to the "Add-Ins" tab on the ribbon.
+ Find and click the "ElementIdReader" button.
+ A TaskDialog will appear, displaying the Element IDs of the selected elements.
### Additional Information
### Exception Handling: The Execute method includes exception handling to capture and display any errors that may occur during the execution of the command.

### Read-Only Transaction: The plugin is set to run in read-only mode, as specified by the Transaction attribute (TransactionMode.ReadOnly). This is suitable for commands that only read information from the Revit model and do not modify it.

### TaskDialog: The selected Element IDs are displayed in a TaskDialog. You can customize the TaskDialog message or add additional functionality within the Execute method.
