#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#include <zlib.h>

int32_t main(int32_t argc, char const *argv[])
{
    int32_t ret = 0;
    char *str = "Hello World!";
    int32_t len = strlen(str);
    int32_t size = len + (len / 100) + 12;
    uint8_t *compressed = (uint8_t *)malloc(size);
    if (compressed == NULL)
    {
        printf("Error allocating memory\n");
        ret = 1;
        goto err;
    }
    uint8_t *uncompressed = (uint8_t *)malloc(len);
    if (uncompressed == NULL)
    {
        printf("Error allocating memory\n");
        ret = 1;
        goto err;
    }

    int32_t result = compress(compressed, &size, (uint8_t *)str, len);
    if (result != Z_OK)
    {
        printf("compress failed\n");
        ret = 1;
        goto err;
    }
    printf("Compressed size: %d\n", size);

    result = uncompress(uncompressed, &len, compressed, size);
    if (result != Z_OK)
    {
        printf("uncompress failed\n");
        ret = 1;
        goto err;
    }
    printf("Uncompressed string: %s\n", uncompressed);

    ret = 0;
err:
    if (compressed)
    {
        free(compressed);
    }
    if (uncompressed)
    {
        free(uncompressed);
    }
    return ret;
}
