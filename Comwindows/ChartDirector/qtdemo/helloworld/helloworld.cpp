#include <QApplication>
#include "qchartviewer.h"


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
 	QChartViewer viewer;

	//
	// Draw Chart and set to QChartViewer
	//

	// The data for the bar chart
    double data[] = {85, 156, 179.5, 211, 123};

	// The labels for the bar chart
    const char *labels[] = {"Mon", "Tue", "Wed", "Thu", "Fri"};

    // Create a XYChart object of size 250 x 250 pixels
    XYChart *c = new XYChart(250, 250);

    // Set the plotarea at (30, 20) and of size 200 x 200 pixels
    c->setPlotArea(30, 20, 200, 200);

    // Add a bar chart layer using the given data
    c->addBarLayer(DoubleArray(data, sizeof(data)/sizeof(data[0])));

    // Set the labels on the x axis.
    c->xAxis()->setLabels(StringArray(labels, sizeof(labels)/sizeof(labels[0])));

    // Output the chart
    viewer.setChart(c);
	
    // Include tool tip for the chart
    viewer.setImageMap(
    	c->getHTMLImageMap("", "", "title='{xLabel}: US${value}K'"));

	// In this sample project, we do not need to chart object any more, so we 
	// delete it now.
    delete c;
    
    //
    // Show the viewer
    //
    
    viewer.show();
    return app.exec();
}
