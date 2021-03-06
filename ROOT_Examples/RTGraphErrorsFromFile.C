int RTGraphErrorsFromFile()
{

    TCanvas* c=new TCanvas();
    c->SetGrid();

    TGraphErrors graph_expected("input1_RTGraphErrorsFromFile.txt",
                                "%lg %lg %lg");
    graph_expected.SetTitle("Measurement XYZ and Expectation length [cm] Arb.Units");
    graph_expected.SetFillColor(kYellow);
    graph_expected.DrawClone("E3AL"); // E3 draws the band

    TGraphErrors graph("input2_RTGraphErrorsFromFile.txt", "%lg %lg %lg");
    graph.SetMarkerStyle(kCircle);
    graph.SetFillColor(0);
    graph.DrawClone("PESame");

    // Draw the Legend
    TLegend leg(.1,.7,.3,.9,"Lab. Lesson 2");
    leg.SetFillColor(0);
    leg.AddEntry(&graph_expected,"Expected Points");
    leg.AddEntry(&graph,"Measured Points");
    leg.DrawClone("Same");

    graph.Print();

    return 0;
}
