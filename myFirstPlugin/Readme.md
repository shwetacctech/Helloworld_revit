# Revit Plugin: HelloWorld
The HelloWorld Revit plugin is a simple external command that displays a "Hello World" message in a TaskDialog. The plugin also adds a button to the Revit ribbon for easy access.

# Overview
### The plugin consists of two main components:

+ Application Class (Application): Implements the IExternalApplication interface to handle the startup and shutdown of the external application. It creates a ribbon panel and adds a push button to trigger the HelloWorld command.

+ HelloWorld Command (HelloWorld): Implements the IExternalCommand interface and serves as the main external command. It displays a TaskDialog with the "Hello World" message.

### Usage
Installation:

Compile the project to generate the plugin DLL.
Copy the DLL to the Revit Addins folder (e.g., C:\ProgramData\Autodesk\Revit\Addins{Revit Version}).
Run the Plugin:

+ Open Revit.
+ Navigate to the "Add-Ins" tab on the ribbon.
+ Find the "NewRibbonPanel" panel.
+ Click the "Hello World" button to trigger the command.
+ Additional Information
+ Large Image: The plugin includes a large image for the button, which is set to a Christmas-themed icon. You can customize the image path by modifying the uriImage variable in the OnStartup method of the Application class.

+ Tool-Tip: The button includes a tool-tip that appears when the user hovers over it. The tool-tip is set to "Say hello to the entire world." You can customize the tool-tip text by modifying the pushButton.ToolTip property in the OnStartup method of the Application class.

+ TaskDialog: The HelloWorld command displays a simple TaskDialog with the "Hello World" message. You can customize the message or add additional functionality within the Execute method of the HelloWorld class.
The ElementIdReader Revit plugin is a simple external command that retrieves and displays the Element IDs of selected elements in the active Revit document. The plugin is set to run in read-only mode.

# Overview
The plugin consists of a single external command class:

# Command Class (Command):
+ Implements the IExternalCommand interface and serves as the main external command. It retrieves the Element IDs of selected elements in the active document and displays the information in a TaskDialog.
+ Usage
+ Installation:

+ Compile the project to generate the plugin DLL.
+ Copy the DLL to the Revit Addins folder (e.g., C:\ProgramData\Autodesk\Revit\Addins{Revit Version}).
### Run the Plugin:

+ Open Revit.
+ Select one or more elements in the Revit model.
+ Navigate to the "Add-Ins" tab on the ribbon.
+ Find and click the "ElementIdReader" button.
+ A TaskDialog will appear, displaying the Element IDs of the selected elements.
+ Additional Information
+ Exception Handling: The Execute method includes exception handling to capture and display any errors that may occur during the execution of the command.

+ Read-Only Transaction: The plugin is set to run in read-only mode, as specified by the Transaction attribute (TransactionMode.ReadOnly). This is suitable for commands that only read information from the Revit model and do not modify it.

+ TaskDialog: The selected Element IDs are displayed in a TaskDialog. You can customize the TaskDialog message or add additional functionality within the Execute method.
