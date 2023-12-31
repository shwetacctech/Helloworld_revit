using Autodesk.Revit.Attributes;
using Autodesk.Revit.DB;
using Autodesk.Revit.UI;
using Autodesk.Revit.UI.Events;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Revit__
{
    [Transaction(TransactionMode.Manual)]
    public class Class1 : IExternalCommand
    {
        public Result Execute(ExternalCommandData commandData, ref string message, ElementSet elements)
        {
            string text = "sample";
            double number = 3.45;
            int intNumber = 4;
            string multipleTypes = "type1|type2|type3";
            List<string> allNames = new List<string>();
            allNames.Add(text);
            allNames.Add(multipleTypes);
            allNames.Add(number.ToString());
            allNames.Add(intNumber.ToString());

            MessageBoxData.Show()
            return Result.Succeeded;
        }
    }
}


























































