#ifndef _XMMS_OUTPUT_H_
#define _XMMS_OUTPUT_H_

#include <glib.h>

#include "xmms/config.h"
#include "xmms/plugin.h"

/*
 * Type definitions
 */

typedef struct xmms_output_St xmms_output_t;


/*
 * Output plugin methods
 */

typedef void (*xmms_output_write_method_t) (xmms_output_t *output, gchar *buffer, gint len);
typedef gboolean (*xmms_output_open_method_t) (xmms_output_t *output);
typedef gboolean (*xmms_output_new_method_t) (xmms_output_t *output);
typedef gboolean (*xmms_output_volume_get_method_t) (xmms_output_t *output, gint *left, gint *right);
typedef void (*xmms_output_flush_method_t) (xmms_output_t *output);
typedef void (*xmms_output_close_method_t) (xmms_output_t *output);
typedef guint (*xmms_output_samplerate_set_method_t) (xmms_output_t *output, guint rate);
typedef guint (*xmms_output_buffersize_get_method_t) (xmms_output_t *output);

/*
 * Public function prototypes
 */

xmms_plugin_t *xmms_output_plugin_get (xmms_output_t *output);
gpointer xmms_output_plugin_data_get (xmms_output_t *output);
void xmms_output_plugin_data_set (xmms_output_t *output, gpointer data);

gboolean xmms_output_volume_get (xmms_output_t *output, gint *left, gint *right);

void xmms_output_flush (xmms_output_t *output);
void xmms_output_pause (xmms_output_t *output);
void xmms_output_resume (xmms_output_t *output);
gboolean xmms_output_is_paused (xmms_output_t *output);

#endif
