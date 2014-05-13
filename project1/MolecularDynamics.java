import java.lang.Math;
import java.io.*;
import java.util.Random;

public class MolecularDynamics {
	
	public void run(double vMax, Force f) throws IOException {
		PositionVerlet pv = new PositionVerlet();
		Random rand = new Random(System.currentTimeMillis());
		int N = 30;
		double h = 0.02;
		
		double[] y = new double[N];
		double[] v = new double[N];
		setInitialConditions(y, v, rand.nextDouble());
		double tEquilibrium = 1000.0;
		double tEnd = 10000.0;
		double t = 0.0;
		double temp;

		double avgTemp = 0;
		PrintWriter tempFile = new PrintWriter("output/temperature.out");
		//PrintWriter energyFile = new PrintWriter("output/energy.out");
		while(t <= tEnd) {
			pv.positionVerlet(h, y, v, f);
			temp = temp(v);
			tempFile.println(temp);
			if(t > tEquilibrium) avgTemp += temp;
			//energyFile.println(af.energy(y, v));
			t += h;
		}
		velocityHist(v, 10, vMax);
		tempFile.close();
		//energyFile.close();

		System.out.println("Average temperature during measurement phase: " + avgTemp*h/(tEnd - tEquilibrium));

		
		
	}
	void velocityHist(double[] v, int nbins, double vMax) throws IOException {
		int N = v.length;
		double binWidth = vMax/nbins;
		double[] bins = new double[nbins];
		double norm = 1.0/(binWidth*N);
		for(int i = 0; i < N; i++) {
			System.out.println(v[i]);
			int bin = (int) ((v[i]+vMax/2)/binWidth);
			bins[bin] = bins[bin] + norm;
		}
		PrintWriter pw = new PrintWriter("output/VelocityHist.out");
		for(int i = 0; i < nbins; i++) {
			pw.println(bins[i]);
			System.out.println(bins[i]);
		}
		pw.close();

	}
	void velocityDist(double T, double binSize) {
	}


	double temp(double[] v) {
		int N = v.length;
		double avg = 0;
		for(int i = 0; i < N; i++) {
			avg += v[i]*v[i];
		}
		return avg/N;
	}

	

	void setInitialConditions(double[] y, double[] v, double delta) {
		int N = y.length;
		for(int i = 0; i < N; i++) {
			y[i] = 0;
			v[i] = Math.sin(2*Math.PI*((double)i + delta)/N);
		}
	}
	public static void main(String[] args) {
		MolecularDynamics md = new MolecularDynamics();
		try {
			md.run(0.4, new AnharmonicForce());
		}
		catch(IOException e) {};
	}
}	
class HarmonicForce extends Force {
 	double force(double y) {
		return -y;
	}
}


