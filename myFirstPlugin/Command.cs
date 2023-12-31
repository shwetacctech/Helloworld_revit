using Autodesk.Revit.DB;
using Autodesk.Revit.UI.Selection;
using Autodesk.Revit.UI;
using System.Collections.Generic;
using System;

[Autodesk.Revit.Attributes.Transaction(Autodesk.Revit.Attributes.TransactionMode.ReadOnly)]
public class Command : IExternalCommand
{
    public Autodesk.Revit.UI.Result Execute(ExternalCommandData commandData,
        ref string message, ElementSet elements)
    {
        try
        {
            // Select some elements in Revit before invoking this command

            // Get the handle of current document.
            UIDocument uidoc = commandData.Application.ActiveUIDocument;

            // Get the element selection of current document.
            Selection selection = uidoc.Selection;
            ICollection<ElementId> selectedIds = uidoc.Selection.GetElementIds();

            if (0 == selectedIds.Count)
            {
                // If no elements selected.
                TaskDialog.Show("Revit", "You haven't selected any elements.");
            }
            else
            {
                String info = "Ids of selected elements in the document are: ";
                foreach (ElementId id in selectedIds)
                {
                    info += "\n\t" + id.IntegerValue;
                }

                TaskDialog.Show("Revit", info);
            }
        }
        catch (Exception e)
        {
            message = e.Message;
            return Autodesk.Revit.UI.Result.Failed;
        }

        return Autodesk.Revit.UI.Result.Succeeded;
    }
    /// </ExampleMethod>
}