
void FitResolution() 
{

    TFile * file = TFile::Open("~/data/hists2012.root");
    TGraphErrors * res = (TGraphErrors*)file->Get("NeutronResolution1");
    double xx,yy,dx,dy;
    for(int i=0; i<res->GetN(); i++) {
        res->GetPoint(i,xx,yy);
        dx = res->GetErrorX(i);
        dy = res->GetErrorY(i);
        res->SetPoint(i,xx/1000.,yy/100.);
        res->SetPointError(i,dx/1000.,dy/100.);
    }

    TF1 * func = new TF1("func","TMath::Sqrt([0]*[0] + [1]*[1]/x + [2]*[2]/x/x)",0.0001,5);
    func->SetParameters(0.1,0.1,0.001);
    func->SetParLimits(0,0,1);
    func->SetParLimits(1,0,1);
    func->SetParLimits(2,0,1);
    func->SetNpx(1000);
    res->Fit(func);

    res->Draw("a*");
}
