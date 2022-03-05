#include <stdio.h>
#include <stdlib.h>
typedef int Para;
typedef struct PolyNomial {
    Para cons;
    Para expo;
    struct PolyNomial *prev;
    struct PolyNomial *next;
}PN;
<<<<<<< HEAD
typedef struct mult{
    Para elem;
    struct mult *next;
}MT;
=======
>>>>>>> 885867c (add the polynomial.)
/* =========All algorithm is section 2.4========= */
PN *InitPoly(Para cons, Para expo);
int insert_polyitem(PN **node, Para cons, Para expo); /* polynomial insert with sort */
void print(char *name, PN *node);
<<<<<<< HEAD
int polynomail_add(PN *first, PN *second); /*  add polynomial item*/
int polynomail_multiply(PN *first, PN *second);
int Init_and_tail_insert(MT *node, Para element);
=======
int polynomail_add(PN *first, PN *second);
>>>>>>> 885867c (add the polynomial.)
/* ============================================== */
int main() {
    PN *start = InitPoly(1, 0);
    PN *restart = InitPoly(1, 0);
    start->cons--;
    restart->cons--;
    Para constants[] = {-2, 0, 5, 10, 5, 6};
    Para exponent[] = {1, 3, 0, 6, 1, 2};
    int length = sizeof(constants) / sizeof(Para);
    for(int i=0;i<length;i++){
        /* printf("This is step %d\n", i); */
        insert_polyitem(&start, constants[i], exponent[i]);
    }
    print("S(x)", start);
    /* for second polynomial */
<<<<<<< HEAD
    Para conses[] = {2, 4, 9, 3};
    Para expos[] = {2, -1, 4, 0};
=======
    Para conses[] = {2, 4, 9, 3, 10};
    Para expos[] = {2, -1, 4, 0, 23652055};
>>>>>>> 885867c (add the polynomial.)
    int lengths = sizeof(conses) / sizeof(Para);
    for(int i=0;i<lengths;i++){
        /* printf("This is step %d\n", i); */
        insert_polyitem(&restart, conses[i], expos[i]);
    }
    print("F(x)", restart);
    printf("Merge the two polynomail\n");
    polynomail_add(start, restart);
<<<<<<< HEAD

    print("test", start);
    print("test", restart);
    printf("Multiplyt the two polynomail\n");
    polynomail_multiply(start, restart);
    print("test", start);
    print("test", restart);
=======
>>>>>>> 885867c (add the polynomial.)
    return 0;
}

PN *InitPoly(Para cons, Para expo)
{
    PN *node;
    if (cons == 0) {
        return NULL;
    }
    node = (PN *) malloc(sizeof(PN));
    if (!node) {
        printf("Malloc error");
        return NULL;
    }
    /* printf("%d|%d\n", cons, expo); */
    node->cons = cons;
    node->expo = expo;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

int insert_polyitem(PN **node, Para cons, Para expo)
{
    PN *need = InitPoly(cons, expo);
    if(!need){
        printf("This node is NULL\n");
        return 1;
    }
    PN *tnode = *node;
    while (tnode) {
        if (need->expo == tnode->expo) {
            tnode->cons += need->cons;
            break;
        } else if (need->expo < tnode->expo) {
            if(!(tnode->prev)){
                tnode->prev = need;
                need->next = tnode;
                *node = need;
                break;
            }else{
                need->prev = tnode->prev;
                tnode->prev->next = need;
                need->next = tnode;
                tnode->prev = need;
                break;
            }
        } else if (!tnode->next) {
            tnode->next = need;
            need->prev = tnode;
            break;
        }
        tnode = tnode->next;
    }
<<<<<<< HEAD
    return 0;
=======
>>>>>>> 885867c (add the polynomial.)
}

void print(char *name, PN *node)
{
    printf("%s = ", name);
    while (node->next) {
        if (node->expo == 0) {
            printf("%d + ", node->cons);
        }else {
            printf("%d*x^%d + ", node->cons, node->expo);
        }
        node = node->next;
    }
    if (node->expo == 0) {
        printf("%d\n", node->cons);
     }else {
        printf("%d*x^%d\n", node->cons, node->expo);
    }
}

int polynomail_add(PN *first, PN *second)
{
    PN *new = InitPoly(1, 0);
    if (!new) {
        printf("Error init");
        return 1;
    }
    PN *monitor=new;
    new->cons--;
    while (first && second) {
        if (first->expo > second->expo) {
<<<<<<< HEAD
            PN *temp = InitPoly(second->cons, second->expo);
            monitor->next = temp;
            monitor = monitor->next;
            second = second->next;
        } else if (first->expo < second->expo) {
            PN *temp = InitPoly(first->cons, first->expo);
            monitor->next = temp;
            monitor = monitor->next;
=======
            monitor->next = second;
            monitor = second;
            second = second->next;
        } else if (first->expo < second->expo) {
            monitor->next = first;
            monitor = first;
>>>>>>> 885867c (add the polynomial.)
            first = first->next;
        } else {
            PN *temp = InitPoly(first->cons + second->cons, first->expo);
            monitor->next = temp;
            monitor = temp;
            first = first->next;
            second = second->next;
        }
    }
    monitor->next = first ? first : second;
    new = new->next;
<<<<<<< HEAD
    print("H(x)", new);
    return 0;
}

int polynomail_multiply(PN *first, PN *second)
{
    PN *new = InitPoly(1, 0);
    MT *constant = (MT *) malloc(sizeof(MT));
    constant->elem = 0, constant->next = NULL;
    MT *exponent = (MT *) malloc(sizeof(MT));
    exponent->elem = 0, exponent->next = NULL;
    new->cons--;
    while (first) {
        PN *temp=second;
        while(temp){
            Init_and_tail_insert(constant, first->cons * temp->cons);
            Init_and_tail_insert(exponent, first->expo + temp->expo);
            temp = temp->next;
        }
        first = first->next;
    }
    constant = constant->next;
    exponent = exponent->next;
    while (constant) {
        insert_polyitem(&new, constant->elem, exponent->elem);
        constant = constant->next, exponent = exponent->next;
    }
    print("M(x)", new);
    return 0;
}

int Init_and_tail_insert(MT *node, Para element)
{
    node->elem++;
    MT *need = (MT *) malloc(sizeof(MT));
    need->elem = element;
    need->next = NULL;
    while(node->next){
        node = node->next;
    }
    node->next = need;
    return 0;
=======
    print("H(X)", new);

>>>>>>> 885867c (add the polynomial.)
}
