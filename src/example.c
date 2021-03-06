#include <mruby.h>
#include <mruby/string.h>
#include <stdio.h>

static mrb_value
mrb_pog(mrb_state *mrb, mrb_value self)
{
	mrb_ensure_string_type(mrb, self);
	printf("%s: A C Extension\n", mrb_str_to_cstr(mrb, self));

	return self;
}

void
mrb_my_silly_extension_gem_init(mrb_state* mrb) {
	struct RClass *class_emote = mrb_define_module(mrb, "Emote");
	mrb_define_class_method(mrb, class_emote, "pog", mrb_pog, MRB_ARGS_NONE());
}

void
mrb_my_silly_extension_gem_final(mrb_state* mrb) {
	/* finalizer */
}
