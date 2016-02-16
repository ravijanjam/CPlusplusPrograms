#include <iostream>


#include <TGraph.h>
#include <TF1.h>

using namespace std;

double* getBins(int nSamples){

	static double bins[100];
	for (int i=0; i<nSamples; i++) bins[i] = i;

	return bins;
}

void RReturnArrayTGraph(){

	double binValue[100]; 

	TF1 *f = new TF1("f", "abs(sin(x))", -6.28, 6.28);

	int nSamples = 100;
	for (int i=0; i<nSamples; i++) 	binValue[i] = f->GetRandom();

	// Get the bins from function
	double *bins; 
	bins = getBins(nSamples);

	// Retrieving samples from the function
	for (int i=0; i < nSamples; i++) {
		cout << "From the function: " << getBins(nSamples)[i] << "  ,";
		cout << "Copied to an array in main program: " << bins[i] << "\n";
	}

	TGraph *g = new TGraph(nSamples, bins, binValue);
	g->Draw();

}

/* 
 * This program, samples a bunch of values from the function
 * and passed into an array. 
 *
 * Another array is generated from a function outiside, which is
 * called in the main and copied into a new array and passed to the
 * TGraph
 *
 * Often times, one might need to do the same type ofcalculation for arrays
 * to be passed into TGraph, which is convenient if done in a function externally. 
 * This program demonstrates
 *
 *
 * /
