int main(void) {
    int *a = malloc(sizeof(int));  // TODO
    a[0] = 10;
    printf("%d\n", a[0]);
    free(a);
}
