typedef struct{
    unsigned long   flags;
    unsigned long   functions;
    unsigned long   decorations;
    long            inputMode;
    unsigned long   status;
    } Hints;


struct Size{
	int height,width;
};
class Color{
	public:
		int r,g,b;
		unsigned long decimal;//Decimal representation for the r,g,b
		Color(){
			r = g = b = 0;
			decimal  = 0;
		}
		Color(unsigned long d){
			decimal = d;
			b = d & 0xff;
			g = (d >> 8) & 0xff;
			r = (d >> 16) & 0xff;
		}
		Color(int red, int green, int blue){
			r = red;
			g = green;
			b = blue;
			decimal = b + (g * 256) + (r * 65536);
		}
		unsigned long printDecimal(){
			return decimal;
		}
};

struct DisplayProperties{
	int height, width, depth;
}DefaultDisplayProp;
