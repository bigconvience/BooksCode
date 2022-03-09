char *month_name(int n) {
	static char *name[] = {
		"Illegal month", "January", "February", "March",
		"April", "May", "June", 
		"July", "Augest", "September",
		"October", "November", "December"
	};

	return (n < 1 || n > 12) ? name[0] : name[n];
}