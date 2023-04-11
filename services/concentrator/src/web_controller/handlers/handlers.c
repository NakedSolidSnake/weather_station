#include <handlers.h>
#include <string.h>
#include <stdlib.h>
#include <service.h>
#include <stdio.h>

const char *page = 
"<!DOCTYPE html>" \
"<head>" \
	"<title>civetweb</title>" \
"</head>" \
  "<body>" \
    "<h1>" \
      "Temperature: %.2lf" \
    "</h1>" \
    "<h1>" \
      "Humidity: %.2lf" \
    "</h1>" \
    "<h1>" \
      "Barometry: %.2lf" \
    "</h1>" \
  "</body>" \
"</html>";

int handler_index (struct mg_connection *conn, void *data)
{

    const struct mg_request_info *ri = mg_get_request_info (conn);

    service_t *service = (service_t *)data;
    sensor_t sensors [SENSOR_AMOUNT];
    service_sensor_get_all (service, sensors);

    if (strcmp (ri->local_uri, "/") == 0)
    {
        char buffer [2048] = {0};
        char size_str [10] = {0};

        snprintf (buffer, 2048, page, sensors[0].value, sensors[1].value, sensors[2].value);
        snprintf (size_str, 10, "%ld", strlen (buffer));
        mg_response_header_start (conn, 200);
        mg_response_header_add (conn, 
                                "Content-Type",
                                "text/html; charset=utf-8",
                                -1);
        mg_response_header_add (conn, "Content-Length", size_str, -1);
        mg_response_header_send (conn);
        mg_write (conn, buffer, strlen (buffer));
    }

    return 200;
}