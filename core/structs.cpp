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
struct DisplayProperties{
	int height, width, depth;
}DefaultDisplayProp;
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

class Frame{
	public:
		static int max_height, max_width;
		static int has_new_frame, buffer_is_set;
		int height, width;
		static unsigned long *buffer;
		Frame(){
			if(max_height==10&&max_width==10){
				max_height = window_height;
				max_width = window_width;
			}
			height = max_height;
			width = max_width;
			allocMemory();
		}
		Frame(int x, int y){
			height = x;
			width = y;
			allocMemory();
		}
		void allocMemory(){
			if(buffer_is_set==0){
				free(buffer);
				buffer = (unsigned long *)malloc(height*width*sizeof(unsigned long));
				for(int i=0;i<height;i++)
					for(int j=0;j<width;j++){
						buffer[(i*width)+j] = 0;
					}
			}
			buffer_is_set = 1;
		}
		unsigned long *obtainBuffer(){return buffer;}
		int display(){
			has_new_frame = 1;
			return 0;
		}
};
int Frame::max_height = 10;
int Frame::max_width = 10;
int Frame::has_new_frame = 0;
int Frame::buffer_is_set = 0;
unsigned long *Frame::buffer = (unsigned long *)malloc(Frame::max_height*Frame::max_width*sizeof(unsigned long));
