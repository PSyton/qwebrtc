project('qwebrtc', 'cpp')

qt5 = import('qt5')
qt5_dep = dependency('qt5', modules: ['Core', 'Quick'])

inc = include_directories('.')

webrtc = subproject('webrtc')
webrtc_dep = webrtc.get_variable('webrtc_dep')

# Work around name collisions with webrtc's sigslot.h
qwebrtc_cargs = '-DQT_NO_KEYWORDS'

moc_headers = files(
    'qwebrtc.h',
    'qwebrtcpeerconnectionfactory.hpp',
    'qwebrtcpeerconnection.hpp',
    'qwebrtcdatachannel.hpp',
    'qwebrtcdatachannel_p.hpp',
    'qwebrtcmediastream.hpp',
    'qwebrtcsessiondescription.hpp',
    'qwebrtcmediatrack.hpp',
    'qwebrtcmediatrack_p.hpp',
    'qwebrtcutilities.hpp',
    'qwebrtcquickvideoitem.hpp',
    'qwebrtcicecandidate.hpp',
    'qwebrtcconfiguration.hpp',
    'qwebrtcdesktopvideosource_p.hpp',
)

moc_files = qt5.preprocess(moc_headers: moc_headers)

sources = files(
    'qwebrtc.cpp',
    'qwebrtcpeerconnectionfactory.cpp',
    'qwebrtcpeerconnection.cpp',
    'qwebrtcdatachannel.cpp',
    'qwebrtcmediastream.cpp',
    'qwebrtcsessiondescription.cpp',
    'qwebrtcmediatrack.cpp',
    'qwebrtcutilities.cpp',
    'qwebrtcquickvideoitem.cpp',
    'qwebrtcicecandidate.cpp',
    'qwebrtcdesktopvideosource.cpp',
)

qwebrtc = static_library('qwebrtc', moc_files, sources,
    cpp_args: qwebrtc_cargs,
    dependencies: [qt5_dep, webrtc_dep])

qwebrtc_dep = declare_dependency(
    link_with: qwebrtc,
    dependencies: [qt5_dep, webrtc_dep],
    include_directories: inc,
)
