#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <arpa/inet.h>

// Function to calculate the IP range for a given CIDR notation
int calculate_ip_range(const char *cidr, uint32_t *start_ip, uint32_t *end_ip) {
    char ip[16];
    int prefix_len;

    // Parse CIDR notation
    if (sscanf(cidr, "%15[^/]/%d", ip, &prefix_len) != 2) {
        return 0; // Invalid CIDR notation
    }

    struct in_addr addr;

    if (inet_pton(AF_INET, ip, &addr) != 1) {
        return 0; // Invalid IP address
    }

    *start_ip = ntohl(addr.s_addr);
    *end_ip = *start_ip | ((1u << (32 - prefix_len)) - 1);

    return 1; // Success
}

// Function to print the IP range
void print_ip_range(uint32_t start_ip, uint32_t end_ip) {
    struct in_addr addr;

    for (uint32_t ip = start_ip; ip <= end_ip; ip++) {
        addr.s_addr = htonl(ip);
        printf("%s\n", inet_ntoa(addr));
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <CIDR>\n", argv[0]);
        return 1; // Incorrect usage
    }

    const char *cidr = argv[1];
    uint32_t start_ip, end_ip;

    if (!calculate_ip_range(cidr, &start_ip, &end_ip)) {
        fprintf(stderr, "Invalid CIDR notation or IP address: %s\n", cidr);
        return 1; // Invalid CIDR notation or IP address
    }

    printf("CIDR netmask supplied was %s\n", cidr);
    print_ip_range(start_ip, end_ip);

    return 0;
}