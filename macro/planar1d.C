{
   // calculate fields
   GeFiCa::Planar1D *detector = new GeFiCa::Planar1D(101);
   detector->UpperBound=1; //1 cm in thickness
   detector->MaxIterations=1e5;
   detector->Csor=1.95;
   detector->V1=2000*GeFiCa::volt;
   //detector->V1=1*GeFiCa::volt; //weight potential boundary 
   detector->V0=0*GeFiCa::volt;
   //detector->SetImpurity(1e10/GeFiCa::cm3);
   //detector->Impurity="1e10*x+0.5e10"; //impurity is 0.5e10/cm3 at z=0, 1.5e10/cm3 at z=1cm.
   detector->Impurity="0"; //weighting potential.
   detector->CalculateField(GeFiCa::kSOR2);
   detector->SaveField("planar1dSOR2.root");
   //impurity=0.2e10
   detector->Impurity="4e10"; 
   detector->CalculateField(GeFiCa::kSOR2);
   detector->SaveField("planar1dSOR2_1.root");


   //impurity=0.4e10
   detector->Impurity="0.4e10"; 
   detector->CalculateField(GeFiCa::kSOR2);
   detector->SaveField("planar1dSOR2_2.root");

   
   //impurity=0.6e10
   detector->Impurity="0.6e10"; 
   detector->CalculateField(GeFiCa::kSOR2);
   detector->SaveField("planar1dSOR2_3.root");


   //impurity=0.8e10
   detector->Impurity="0.8e10"; 
   detector->CalculateField(GeFiCa::kSOR2);
   detector->SaveField("planar1dSOR2_4.root");


   //impurity=1e10
   detector->Impurity="1e10"; 
   detector->CalculateField(GeFiCa::kSOR2);
   detector->SaveField("planar1dSOR2_5.root");


//impurity=1.5e10
   detector->Impurity="1.5e10";
   detector->CalculateField(GeFiCa::kSOR2);
  detector->SaveField("planar1dSOR2_6.root");

//impurity=1.0e10*z+0.5e10
   detector->Impurity="1e10*x+0.5e10";
   detector->CalculateField(GeFiCa::kSOR2);
  detector->SaveField("planar1dSOR2_7.root");


   TCanvas * cvs=new TCanvas();
   gStyle->SetPadTopMargin(0.02);
   gStyle->SetPadRightMargin(0.01);
   gStyle->SetPadLeftMargin(0.13);
   gStyle->SetLabelFont(22,"XY");
   gStyle->SetLabelSize(0.06,"XY");
   gStyle->SetTitleSize(0.05,"XY");
   gStyle->SetTitleFont(22,"XY");
   //gStyle->SetLegendTextSize(0.04);

   // generate graphics
   TChain *tn = new TChain("t");
   tn->Add("planar1dSOR2.root");
   //tn->Draw("p:c1");
   tn->Draw("e1:c1");
   TGraph *gn = new TGraph(tn->GetSelectedRows(), tn->GetV2(), tn->GetV1());

   TChain *tn_1 = new TChain("t");
   tn_1->Add("planar1dSOR2_1.root");
   //tn_1->Draw("p:c1");
   tn_1->Draw("e1:c1");
   TGraph *gn_1 = new TGraph(tn_1->GetSelectedRows(), tn_1->GetV2(), tn_1->GetV1());
  

   TChain *tn_2 = new TChain("t");
   tn_2->Add("planar1dSOR2_2.root");
  // tn_2->Draw("p:c1");
  //tn_2->Draw("e1:c1");
   TGraph *gn_2 = new TGraph(tn_2->GetSelectedRows(), tn_2->GetV2(), tn_2->GetV1());
   

   TChain *tn_3 = new TChain("t");
   tn_3->Add("planar1dSOR2_3.root");
  // tn_3->Draw("p:c1");
  tn_3->Draw("e1:c1");
   TGraph *gn_3 = new TGraph(tn_3->GetSelectedRows(), tn_3->GetV2(), tn_3->GetV1());
   

   TChain *tn_4 = new TChain("t");
   tn_4->Add("planar1dSOR2_4.root");
  // tn_4->Draw("p:c1");
  tn_4->Draw("e1:c1");
   TGraph *gn_4 = new TGraph(tn_4->GetSelectedRows(), tn_4->GetV2(), tn_4->GetV1());
   

   TChain *tn_5 = new TChain("t");
   tn_5->Add("planar1dSOR2_5.root");
  // tn_5->Draw("p:c1");
  tn_5->Draw("e1:c1");
   TGraph *gn_5 = new TGraph(tn_5->GetSelectedRows(), tn_5->GetV2(), tn_5->GetV1());
   
   TChain *tn_6 = new TChain("t");
   tn_6->Add("planar1dSOR2_6.root");
 //  tn_6->Draw("p:c1");
  tn_6->Draw("e1:c1");
   TGraph *gn_6 = new TGraph(tn_6->GetSelectedRows(), tn_6->GetV2(), tn_6->GetV1());
   
   TChain *tn_7 = new TChain("t");
   tn_7->Add("planar1dSOR2_7.root");
 //  tn_7->Draw("p:c1");
  tn_7->Draw("e1:c1");
   TGraph *gn_7 = new TGraph(tn_7->GetSelectedRows(), tn_7->GetV2(), tn_7->GetV1());
   
   TChain *ta = new TChain("t");
   ta->Add("planar1dTrue.root");
   //ta->Draw("p:c1");
   TGraph *ga = new TGraph(ta->GetSelectedRows(), ta->GetV2(), ta->GetV1());

   // make final plot
   gn->SetLineColor(4);
   gn->SetLineWidth(2);
   gn_1->SetLineColor(2);
   gn_1->SetLineWidth(2);
   gn_2->SetLineColor(1);
   gn_2->SetLineWidth(2);
   gn_3->SetLineColor(3);
   gn_3->SetLineWidth(2);
   gn_4->SetLineColor(46);
   gn_4->SetLineWidth(2);
   gn_5->SetLineColor(6);
   gn_5->SetLineWidth(2);
   gn_6->SetLineColor(5);
   gn_6->SetLineWidth(2);
   gn_7->SetLineColor(9);
   gn_7->SetLineWidth(2);
   
   ga->SetLineColor(kRed);
   gn->SetTitle("");
   gn->GetXaxis()->SetTitle("Thickness [cm]");
   gn->GetYaxis()->SetTitle("Potential [V]");
   gn->GetYaxis()->SetTitleOffset(1.2);

   gn->Draw("l");
   
   gn_1->Draw("l");
  /*
   gn_2->Draw("l");
   gn_3->Draw("l");
   gn_4->Draw("l");
   gn_5->Draw("l");
   gn_6->Draw("l");
   gn_7->Draw("l");
*/
   TLegend *leg = new TLegend(0.2,0.6,0.5,0.8);
   leg->SetBorderSize(0);
   
   leg->AddEntry(gn,"#rho=0/cm^{3}","l");
   leg->AddEntry(gn_1,"#rho=0.2*10^{10}/cm^{3}","l");
   leg->AddEntry(gn_2,"#rho=0.4*10^{10}/cm^{3}","l");
   leg->AddEntry(gn_3,"#rho=0.6*10^{10}/cm^{3}","l");
   leg->AddEntry(gn_4,"#rho=0.8*10^{10}/cm^{3}","l");
   leg->AddEntry(gn_5,"#rho=1.0*10^{10}/cm^{3}","l");
   leg->AddEntry(gn_6,"#rho=1.5*10^{10}/cm^{3}","l");
   leg->AddEntry(gn_7,"#rho=1.0*10^{10}*z+0.5*10^{10}","l");
   
   //leg->AddEntry(gn,"#rho=1.0*10^{10}*z+0.5*10^{10}","l");
   //leg->AddEntry(gn,"SOR2","p");
 //  leg->AddEntry(ga,"Analyic","l");
   leg->SetTextSize(0.05);
   leg->Draw();
   
   cvs->SaveAs("planar1d.png");
}
