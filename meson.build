project('ring', 'c')

subdir('checktests')

dep = [
  dependency('glib-2.0'),
  dependency('gio-unix-2.0'),
]

lib_src = files(['ring_buffer.c'])

extra_cflags = ['-W',
                '-Wformat=2',
                '-Wpointer-arith',
                '-Winline',
                '-Wstrict-prototypes',
                '-Wmissing-prototypes',
                '-Wdisabled-optimization',
                '-Wfloat-equal',
                '-Wall',
                '-Wno-unused-parameter',
                '-Werror']

main = executable('ring',
                  sources: ['main.c', lib_src],
                  dependencies: dep,
                  c_args: extra_cflags,
                  install: true)

