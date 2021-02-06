void HistFill(double *q2, double *omega, double *Wvar, double *en_recon1, double *weight, double *p_perp)
{/*
    //--Defining Constants--//
    const double m_prot = 0.9382720813,m_neut=0.939565,H3_bind_en=0.008481,He4_bind_en=0.0283,C12_bind_en=0.09215, B_bind_en=0.0762,He3_bind_en=0.0077,D2_bind_en=0.00222,Fe_bind_en=0.49226,Mn_bind_en=0.4820764;
    const double Mpi = 0.139570, e_mass=0.000510998;
    const int ind_em=0;
    TLorentzVector V4_p_corr;
    double prot_mom_corr = ProtonMomCorrection_He3_4Cell(ftarget,V4_p,prot_vert_corr);
    V4_p_corr.SetPxPyPzE(prot_mom_corr*cx[index_p[0]],prot_mom_corr*cy[index_p[0]],prot_mom_corr*cz[index_p[0]],TMath::Sqrt(m_prot*m_prot+prot_mom_corr*prot_mom_corr));
    p_kin = V4_p_corr.E() - m_prot;
    double N_2pion_1prot = 0
    double N_1pion_1prot[2] = {0}
    double N_1pion_2prot = 0;
    double N_1pion_1prot[2] = {0};
    double P_2p2pi_2p1pi[2][2] = {0}
    double N_1pi_1p_0phot[2] = {0};
    double N_1pi_1p_1phot[2] = {0};
    double N_1pi_2p_1phot = 0;
    double N_1pi_2p_0phot = 0;
    double N_1pi_3p_1phot = 0;
    double N_1pi_3p_0phot = 0;
    int index_p[20],ind_p,index_pi[20],ind_pi, ind_pi_phot[20];

    //--Defining V4_el(?)--//
    TLorentzVector V4_el(p[ind_em]*cx[ind_em],p[ind_em]*cy[ind_em],p[ind_em]*cz[ind_em],TMath::Sqrt(p[ind_em]*p[ind_em]+e_mass*e_mass));
    //----Defining Mott Cross Section ---// Notes: Could not locate V4_el.E() Definition
    double fine_struc_const=0.007297;
    double Mott_cross_sec=(fine_struc_const*fine_struc_const*(cz[ind_em]+1))/(2*V4_el.E()*V4_el.E()*(1-cz[ind_em])*(1-cz[ind_em])); */

    //---Defining Histograms--//
    TH1F *h1_Q2_sub = new TH1F("h1_Q2_sub","",200,0,6);
    h1_Q2_sub->Sumw2();
    TH1F *h1_omega_sub = new TH1F("h1_omega_sub","",200,0,5);
    h1_omega_sub->Sumw2();
    TH1F *h1_Wvar_sub = new TH1F("h1_Wvar_sub","",200,0,3);
    h1_Wvar_sub->Sumw2();
    TH2F *h2_Wvar_Q2_sub = new TH2F("h2_Wvar_Q2_sub","", 200,0,3,200,0,5);
    h2_Wvar_Q2_sub->Sumw2();
    TH2F *h2_omega_Q2_sub = new TH2F("h2_omega_Q2_sub","",200,0,3.5,200,0,5);
    h2_omega_Q2_sub->Sumw2();
    TH2F *h2_cal_Wvar = new TH2F("h2_cal_Wvar","",200,0,5,200,0,5);
    h2_cal_Wvar->Sumw2();
    TH1F *h1_p_perp_sub = new TH1F("h1_p_perp_sub","",400,0,1);
    h1_p_perp_sub->Sumw2();

    //Function Arguments--//
    h1_Q2_sub->Fill(q2,weight);
    h1_omega_sub->Fill(omega,weight);
    h1_Wvar_sub->Fill(Wvar,weight);
    h2_Wvar_Q2_sub->Fill(Wvar, q2,weight);
    h2_omega_Q2_sub->Fill(omega,q2,weight);
    h2_cal_Wvar->Fill(en_recon1[0], Wvar, weight);
    h1_p_perp_sub->Fill(p_perp[0],weight);
    if(p_perp[0] > 0 && p_perp[0] < 0.2)
    {
      h1_cal_p_slice1_sub->Fill(en_recon1[0], weight);
    }
    if(p_perp[0] > 0.2 && p_perp[0] < 0.4)
    {
      h1_cal_p_slice2_sub->Fill(en_recon1[0], weight);
    }
    if(p_perp[0] > 0.4)
    {
      h1_cal_p_slice3_sub->Fill(en_recon1[0], weight);
    }
}
