%bcond_without python
%if %{with python}
%define python_sitearch %(python2 -c "from distutils.sysconfig import get_python_lib; print(get_python_lib(1))")
%define python_prefix %(python2 -c "import sys; print(sys.prefix)")
%{?filter_setup:
%filter_provides_in %{python_sitearch}/perfmon/.*\.so$
%filter_setup
}
%endif

Name:		libpfm
Version:	4.9.0
Release:	1%{?dist}

Summary:	Library to encode performance events for use by perf tool

Group:		System Environment/Libraries
License:	MIT
URL:		http://perfmon2.sourceforge.net/
Source0:	http://sourceforge.net/projects/perfmon2/files/libpfm4/%{name}-%{version}.tar.gz
%if %{with python}
BuildRequires:	python2
BuildRequires:	python2-devel
BuildRequires:	python2-setuptools
BuildRequires:	swig
%endif
BuildRoot:	%{_tmppath}/%{name}-%{version}-%{release}-root-%(%{__id_u} -n)

%description

libpfm4 is a library to help encode events for use with operating system
kernels performance monitoring interfaces. The current version provides support
for the perf_events interface available in upstream Linux kernels since v2.6.31.

%package devel
Summary:	Development library to encode performance events for perf_events based tools
Group:		Development/Libraries
Requires:	%{name}%{?_isa} = %{version}-%{release}

%description devel
Development library and header files to create performance monitoring
applications for the perf_events interface.

%package static
Summary:	Static library to encode performance events for perf_events based tools
Group:		Development/Libraries
Requires:	%{name}%{?_isa} = %{version}-%{release}

%description static
Static version of the libpfm library for performance monitoring
applications for the perf_events interface.

%if %{with python}
%package -n python2-libpfm
%{?python_provide:%python_provide python2-libpfm}
Summary:	Python bindings for libpfm and perf_event_open system call
Group:		Development/Languages
Requires:	%{name}%{?_isa} = %{version}-%{release}

%description -n python2-libpfm
Python bindings for libpfm4 and perf_event_open system call.
%endif

%prep
%setup -q

%build
%if %{with python}
%global python_config CONFIG_PFMLIB_NOPYTHON=n
%else
%global python_config CONFIG_PFMLIB_NOPYTHON=y
%endif
make %{python_config} %{?_smp_mflags} \
     OPTIM="%{optflags}" LDFLAGS="%{build_ldflags}"


%install
rm -rf $RPM_BUILD_ROOT

%if %{with python}
%global python_config CONFIG_PFMLIB_NOPYTHON=n PYTHON_PREFIX=$RPM_BUILD_ROOT/%{python_prefix}
%else
%global python_config CONFIG_PFMLIB_NOPYTHON=y
%endif

make \
    PREFIX=$RPM_BUILD_ROOT%{_prefix} \
    LIBDIR=$RPM_BUILD_ROOT%{_libdir} \
    %{python_config} \
    LDCONFIG=/bin/true \
    install

%post -p /sbin/ldconfig
%postun	-p /sbin/ldconfig

%files
%doc README
%{_libdir}/lib*.so.*

%files devel
%{_includedir}/*
%{_mandir}/man3/*
%{_libdir}/lib*.so

%files static
%{_libdir}/lib*.a

%if %{with python}
%files -n python2-libpfm
%{python_sitearch}/*
%endif

%changelog
* Mon Jun 4 2018 William Cohen <wcohen@redhat.com> 4.9.0-1
- Update spec file.

* Tue Feb 9 2016 William Cohen <wcohen@redhat.com> 4.6.0-1
- Update spec file.

* Wed Nov 13 2013 Lukas Berk <lberk@redhat.com> 4.4.0-1
- Intel IVB-EP support
- Intel IVB updates support
- Intel SNB updates support
- Intel SNB-EP uncore support
- ldlat support (PEBS-LL)
- New Intel Atom support
- bug fixes

* Tue Aug 28 2012 Stephane Eranian  <eranian@gmail.com> 4.3.0-1
- ARM Cortex A15 support
- updated Intel Sandy Bridge core PMU events
- Intel Sandy Bridge desktop (model 42) uncore PMU support
- Intel Ivy Bridge support
- full perf_events generic event support
- updated perf_examples
- enabled Intel Nehalem/Westmere uncore PMU support
- AMD LLano processor supoprt (Fam 12h)
- AMD Turion rocessor supoprt (Fam 11h)
- Intel Atom Cedarview processor support
- Win32 compilation support
- perf_events excl attribute
- perf_events generic hw event aliases support
- many bug fixes

* Wed Mar 14 2012 William Cohen <wcohen@redhat.com> 4.2.0-2
- Some spec file fixup.

* Wed Jan 12 2011 Arun Sharma <asharma@fb.com> 4.2.0-0
Initial revision
