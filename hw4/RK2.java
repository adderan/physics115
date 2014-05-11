import java.lang.Math;

public class RK2 {
	
	void rk2 (double t, double[] x, Derivs d, double h, int M) {
		double[] k1 = new double[M];
		double[] k2 = new double[M];
		double[] xp = new double[M];
		
		d.derivs(t, x, k1);
		for(int i = 0; i < M; i++) {
			xp[i] = x[i] + h*k1[i];
		}
		d.derivs(t+h, xp, k2);
		for(int i = 0; i < M; i++) {
			x[i] += 0.5 * h * (k1[i] + k2[i]);
		}
	}
	void runRK2 (double h, double x0, double v0, double tn) {
		int M = 2;
		double[] x = new double[M];
		double t0 = 0;
		int n = (int)(tn/h);
		x[0] = x0;
		x[1] = v0;
		double t = t0;
		double en;
		double en0 = v0*v0/2 + x0*x0*x0*x0/4;
		double maxEnergyDiff = 0;
		System.out.println("     Time            x            p          Energy");
		for(int i = 0; i < n; i++) {
			rk2(t, x, new Derivs(), h, M);
			t += h;
			en = x[1]*x[1]/2 + x[0]*x[0]*x[0]*x[0]/4;
			if(Math.abs(en-en0) > maxEnergyDiff) maxEnergyDiff = Math.abs(en-en0);
			System.out.printf("%12.6f %12.6f %12.6f %12.6f \n", t, x[0], x[1], en);
			//System.out.printf("%12.6f \n", x[1]);
		}
		System.out.println("Maximum deviation from true energy: " + maxEnergyDiff + "\n");
	}
	
}