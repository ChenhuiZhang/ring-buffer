check_dep = dependency('check', required:false)
if not check_dep.found() or meson.is_cross_build()
    subdir_done()
endif

lib_dep = [
  dependency('glib-2.0'),
  dependency('gio-unix-2.0'),
]


test_env = environment()
test_env.append('VALGRIND_OPTS',
                '--error-exitcode=30',
                '--error-limit=no',
                '--errors-for-leak-kinds=definite,indirect',
                '--leak-check=full',
                '--num-callers=10',
                '--show-leak-kinds=definite,indirect',
                separator: ' ')

# Build checktests executable program.
sources = files('check_ring_buffer.c', '../ring_buffer.c')

exe = executable('ring_buffer', sources,
                 include_directories: include_directories('..'),
                 dependencies: [lib_dep, check_dep])

test('Ring Buffer Unit Tests', exe, env: test_env)
