import java.lang.Math;

public class VelocityVerlet {
	
	public void velocityVerlet(double h, double[] x, double[] v, double t0, double tn, Data d) {
		int M = (int) ((tn - t0)/h);
		
		//double x[] = new double[dimensions];  //divide all indexes by 2 to get value of t for that index. 
		//double v[] = new double[dimensions];
		
		//v[0] = v0;
		//x[0] = x0;
		
		int dimensions = x.length;

		double energy = 0;
		double energy0 = d.energy(x,v); 
		double[] force = d.F(x);
		double maxEnergyDiff = 0;
		double vmid, xend, vend;
		for(int j = 0; j < M; j++) {
			System.out.printf("%12.5f ", (double)j*h);
			for(int i = 0; i < dimensions; i++) {
				vmid = v[i] + 0.5*h*force[i];
				xend = x[i] + h*vmid;
				x[i] = xend;
				force = d.F(x);
				vend = vmid + 0.5*h*force[i];
				v[i] = vend;
				System.out.printf("%12.5f %12.5f", x[i], v[i]);
				if(Math.abs(d.energy(x, v) - energy0) > maxEnergyDiff) maxEnergyDiff = Math.abs(d.energy(x,v)-energy0);
			}
			System.out.printf("%12.5f \n", d.energy(x,v));
			
		}
		System.out.println("Maximum deviation from true energy: " + maxEnergyDiff + "\n");
	}
}

		
		
		
			