struct point {
	int x;
	int y;
}

struct rect {
	struct point pt1;
	struct point pt2;
}

struct rect screen;
struct point middle;
struct point makepoint(int, int);

screen.pt1 = makepoint(0, 0);
screen.pt2 = makepoint(XMAX, YMAX);
middle = makepoint((screen.pt1.x + screen.pt2.x)/2, (screen.pt1.y + screen.pt2.y)/2);

/*makepoint: make a point from x and y components*/
struct point makepoint(int x, int y)
{
	struct point temp;

	temp.x = x;
	temp.y = y;
	return temp;
}

/*addpoint: add two points*/
struct point addpoint(struct point p1, struct point p2)
{
	p1.x += p2.x;
	p1.y += p2.y;

}

/*ptinrect: return 1 if p in r, 0 if not
 * following convention that a rectangle includes its left and bottom sides, but not its top and right sides
 * also assuming p1 coordinates are less than p2 coordinates*/
int ptinrect(struct point p, struct rect r)
{
	return p.x >= r.pt1.x && p.x < r.pt2.x &&
		p.y >= r.pt1.y && p.y < r.pt2.y;
}

#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))

/*canonrect: canonicalize coordinates of rectangle*/
struct rect canonrect(struct rect r)
{
	struct rect temp;

	temp.pt1.x = min(r.pt1.x, r.pt2.x);
	temp.pt1.y = min(r.pt1.y, r.pt2.y);
	temp.pt2.x = min(r.pt1.x, r.pt2.x);
	temp.pt2.y = min(r.pt1.y, r.pt2.y);
	return temp;
}

void pointerdemo()
{
	struct point origin, *pp;

	pp = &origin;
	//'normal' notation
	printf("origin is (%d,%d)\n", (*pp).x, (*pp).y);
	//special notation: p->member-of-structure (where p is a pointer)
	printf("origin is (%d,%d)\n", p->x, p->y);

	//demonstration 2
	struct recr r, *rp = &r;
	//four equivalent expressions.
	r.pt1.x;
	rp->pt1.x;
	(r.pt1).x;
	(rp->pt1).x;

	//note on precedence
	struct {
		int len;
		char *str;
	} *p;

	++p->len //increments len, because . | -> | () | [] are the highest precedent operators, so ++p->len implies ++(p->len)

}
