import 'dart:ffi' as ffi;

class MathsExpBindings {
  /// Holds the symbol lookup function.
  final ffi.Pointer<T> Function<T extends ffi.NativeType>(String symbolName)
      _lookup;

  /// The symbols are looked up in [dynamicLibrary].
  MathsExpBindings(ffi.DynamicLibrary dynamicLibrary)
      : _lookup = dynamicLibrary.lookup;

  /// The symbols are looked up with [lookup].
  MathsExpBindings.fromLookup(
      ffi.Pointer<T> Function<T extends ffi.NativeType>(String symbolName)
          lookup)
      : _lookup = lookup;

  int sum(
    int a,
    int b,
  ) {
    return _sum(
      a,
      b,
    );
  }

  late final _sumPtr =
      _lookup<ffi.NativeFunction<ffi.IntPtr Function(ffi.IntPtr, ffi.IntPtr)>>(
          'sum');
  late final _sum = _sumPtr.asFunction<int Function(int, int)>();

  int sum_long_running(
    int a,
    int b,
  ) {
    return _sum_long_running(
      a,
      b,
    );
  }

  late final _sum_long_runningPtr =
      _lookup<ffi.NativeFunction<ffi.IntPtr Function(ffi.IntPtr, ffi.IntPtr)>>(
          'sum_long_running');
  late final _sum_long_running =
      _sum_long_runningPtr.asFunction<int Function(int, int)>();
  
  double diff(String eq, double x,){
    return _diff(eq,x);
  }

  late final _diffPtr =
  _lookup<ffi.NativeFunction<ffi.Double Function(, ffi.Double)>>(
      'sum_long_running');
  late final _diff =
  _diffPtr.asFunction<double Function()>();
}
